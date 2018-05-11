#include "RSA.h"

RSA::RSA()
{
    this->p = 17;
    this->q = 11;
    this->n = p * q;
    this->phi = (p - 1) * (q - 1);
    this->e = 7;
    this->d = 23;
}

RSA::RSA(int p, int q)
{
    if ((p >= 10000)&&(p <= 100000)&&(q >= 10000)&&(q <= 100000)
    &&(isPrime(p, THRESH) && isPrime(q, THRESH)))
    {
        this->p = p;
        this->q = q;
        this->n = p * q;
        this->phi = (p - 1) * (q - 1);
        this->e = findE(phi);
        this->d = findD(e, phi);
        std::cout << "p   = " << p << '\n'
                  << "q   = " << q << '\n'
                  << "n   = " << n << '\n'
                  << "phi = " << phi << '\n'
                  << "e   = " << e << '\n'
                  << "d   = " << d << '\n';
      }
    else
        throw "ERROR : invalid keys\n";
}

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
bool RSA::isPrime(int p, int t)
{
    srand((unsigned)time(NULL));
    int a = 0;
    int e = 0;
    int r;

    for (int i = 0; i < t; i ++)
    {
        a = (rand() % p - 1) + 1;
        e = (p - 1) / 2;
        r = ((int)pow(a, e)) % p;
        if (r % p == p - 1)
             return false;
    }

    return true;
}

int RSA::joinBlock(int a, int b)
{
    return (a * 1000) + b;
}

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

    int temp = (rand()%a/2)+1;
    while (extendedGcd(temp, a, &x, &y) != 1)
        --temp;

    return temp;
}

u64 RSA::findD(int x , int t)
{
    // int x, y;
    // extendedGcd(a,b,&x,&y);
    
    // if((a * x) + (b * y) == 1)
    //     return x;
    // else 
    //     throw "error getting d key";

    u64 k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

std::string RSA::encrypt(std::string plaintext)
{
    std::vector<int> vec = getEncryptVec(plaintext);
    // std::vector<int> vec;
    // vec.push_back(plaintext[0]);
    std::vector<int> encrypt;
    std::string ciphertext = "";
    u64 c, a, b;

    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        c = calcExp(*it, e, n);
        std::cout << *it<<"^"<<e<<" mod "<<n<<" = "<<c<<'\n';
        ciphertext += c;
        std::cout << ciphertext << '\n';
    }
    std::cout << ciphertext << '\n';

    return ciphertext;
}

std::string RSA::decrypt(std::string ciphertext)
{
    std::cout << "Decrypt" << '\n';
    std::vector<int> vec = getDecryptVec(ciphertext);
    // std::vector<int> vec;
    // vec.push_back(ciphertext[0]);
    std::vector<u64> decrypt;
    std::string plaintext = "";
    u64 m, a, b;

    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        m = calcExp(*it, d, n);
        std::cout << *it<<"^"<<d<<" mod "<<n<<"= "<<m<<'\n';
        splitBlock(m, &a, &b);
        plaintext += (char)a + (char)b;
    }
    std::cout << plaintext << '\n';
    return plaintext;
}

std::vector<int> RSA::getEncryptVec(std::string text)
{
    std::vector<int> v;
    std::string temp = "";
    int count = 0;
    char a,b;

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
        else if (i == text.length()-1)
        {
            // if the string is odd add padding to the end
            a = temp[0];
            v.push_back(joinBlock((int)a, 0));
        }
    }

    return v;
}

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


u64 RSA::calcExp(u64 a, u64 b, u64 n)
{
    u64 ret = 1;

    a = a % n;

    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % n;

        b = b>>1;
        a = (a * a) % n;
    }

    return ret;
}