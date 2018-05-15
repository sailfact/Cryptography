/// RSA.cpp
/// Author : Ross Curley
/// StdID : 19098081
/// implmentation of RSA public key encryption algorithm
/// in C++
#include "RSA.h"
/// RSA::RSA
/// Constructor for RSA class
/// takes two ints checks if they are prime and between 10,000 and 100,000
/// then calculates the public and private keys required for RSA algorithm
RSA::RSA(int p, int q)
{
    if ((p >= 10000) && (p <= 100000) && (q >= 10000) && (q <= 100000) && (isPrime(p, THRESH) && isPrime(q, THRESH)))
    {
        this->p = p;
        this->q = q;
        this->n = p * q;
        this->phi = (p - 1) * (q - 1);
        this->e = findE(phi);
        try
        {
            this->d = findD(e, phi);
        }
        catch (const char *msg)
        {
            throw msg;
        }
    }
    else
        throw "ERROR : invalid keys\n";
}

/// RSA::extendedGcd
/// c++ implementation of the Extended Euclidean Alogorithm
/// returns gcd aswell as x and y via reference
/// where ax + by = gcd
int RSA::extendedGcd(int a, int b, int *x, int *y)
{
    int tempX, tempY, gcd;
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    gcd = extendedGcd(b % a, a, &tempX, &tempY);

    *x = tempY - (b / a) * tempX;
    *y = tempX;

    return gcd;
}

/// isPrime
/// uses Lehmann Algorithm to test
/// validity of Prime given to a certain threshold
bool RSA::isPrime(u64 p, int t)
{
    srand((unsigned)time(NULL));
    int a = 0;
    int e = 0;
    int r;
    bool ret;

    for (int i = 0; i < t; i ++)
    {
        a = (rand()%p-1)+1;
        e = (p-1)/2;
        r = calcExp(a,e,p);
        if (r % p != 1 && r % p != p - 1)
            return false;
        else
            ret = true;
    }

    return ret;
}

/// RSA::joinBlock
/// takes two ascii codes and returns them as one block
int RSA::joinBlock(int a, int b)
{
    return (a * 1000) + b;
}

/// RSA::splitBlock
/// takes a block
/// and splits it into two ascii codes
/// and returns them via reference
void RSA::splitBlock(u64 block, u64 *a, u64 *b)
{
    *a = block / 1000;
    *b = block % 1000;
}

/// RSA::findE
/// finds a u64 integer such that
/// 1 < e < phi & gcd(e, phi) = 1
u64 RSA::findE(u64 a)
{
    int x, y;
    srand((unsigned)time(NULL));

    int temp = (rand() % a / 2) + 1;
    while (extendedGcd(temp, a, &x, &y) != 1)
        --temp;

    return temp;
}

/// RSA::findD
/// uses extended euclidean algorithm to find
/// the private key d
u64 RSA::findD(int a, int b)
{
    int x, y;
    extendedGcd(a, b, &x, &y);

    if ((a * x) + (b * y) == 1)
        return x;
    else
        throw "error getting d key";
}

/// RSA::encrypt
/// takes plaintext turns it into a vector for every two characters 
/// then for each block encrypt with rsa 
std::string RSA::encrypt(std::string plaintext)
{
    std::vector<int> vec = getEncryptVec(plaintext);
    std::vector<int> encrypt;
    std::string ciphertext = "";
    u64 c, a, b;

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
    
        c = calcExp(*it, e, n); // encrypt
        std::stringstream convert;
        convert << c;
        ciphertext += convert.str() + " ";  // add to cipher text seperated by a space
    }

    return ciphertext;
}

/// RSA::decrypt
/// takes ciphertext and turns it into a vector for every block
/// then for every element in the vector
/// decrypts the block
std::string RSA::decrypt(std::string ciphertext)
{
    std::vector<int> vec = getDecryptVec(ciphertext);
    std::vector<u64> decrypt;
    std::string plaintext = "";
    u64 m, a, b;

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        m = calcExp(*it, d, n);       // decrypt block
        splitBlock(m, &a, &b);        // split block
        plaintext.push_back((char)a); // add a and b to plain text
        plaintext.push_back((char)b);
    }

    return plaintext;
}

/// RSA::getEncryptVec
/// gets every 2 characters in the text
/// joins them into one block and places it into a vector
/// if there is an odd amount of characters it is padded with zero/null
std::vector<int> RSA::getEncryptVec(std::string text)
{
    std::vector<int> v;
    std::string temp = "";
    int count = 0;
    char a, b;

    for (int i = 0; i < text.length(); ++i)
    {
        temp += text[i];
        if (temp.length() == 2)
        {
            a = temp[0];
            b = temp[1];
            v.push_back(joinBlock((int)a, (int)b));
            temp = "";
        }
        else if (i == text.length() - 1)
        {
            // if the string is odd add padding to the end
            a = temp[0];
            v.push_back(joinBlock((int)a, 0));
        }
    }

    return v;
}

/// RSA::getDecryptVec
/// gets each individual block from the cipher text and places them
/// in a vector
std::vector<int> RSA::getDecryptVec(std::string ciphertext)
{
    std::vector<int> v;
    std::string temp = "";

    for (int i = 0; i < ciphertext.size(); i++)
    {
        if (ciphertext[i] != ' ')
        {
            temp += ciphertext[i];
        }
        else
        {
            v.push_back(atoi(temp.c_str()));
            temp = "";
        }
    }

    return v;
}

/// RSA::calcExp
/// calculates a^n mod n
/// using Exponentiation in Modular Arithmetic
u64 RSA::calcExp(u64 a, u64 b, u64 n)
{
    u64 ret = 1;

    a = a % n;

    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % n;

        b = b >> 1;
        a = (a * a) % n;
    }

    return ret;
}