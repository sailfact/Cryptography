#include "RSA.h"

RSA::RSA(int p, int q)
{
    if ((p >= 10000)&&(p <= 100000)&&(q >= 10000)&&(q <= 100000)
    &&(isPrime(p, THRESH) && isPrime(q, THRESH)))
    {
        this->p = p;
        this->q = q;
        this->n = p * q;
        this->eulerTotient = (p-1) * (q-1);
        this->e = findE(n, eulerTotient);
        this->d = findD(p,q,e);
    }
    else
        throw "ERROR : invalid keys\n";
}

int RSA::extendedGcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int tempX, tempY;
    int gcd = extendedGcd(b%a, a, &tempX, &tempY);

    *x = tempY - (b/a) * tempX;
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
        a = (rand()%p-1)+1;
        e = (p-1)/2;
        r = ((int)pow(a,e)) % p;
        if (r % p == p - 1)
             return false;
    }

    return true;
}

int RSA::joinBlock(int a, int b)
{
    std::cout << a << " : " << b << " = " << (a*1000)+b <<'\n';
    return (a * 1000) + b;
}

int RSA::splitBlock(int block, int *a, int *b)
{
    *a = block / 1000;
    *b = block % 1000;
}

int RSA::findE(int a, int n)
{
    int x, y;
    srand((unsigned)time(NULL));

    int temp = (rand()%n-1)+1;
    while (extendedGcd(temp, a, &x, &y) != 1)
        --temp;

    return temp;
}

int RSA::findD(int a,int b, int e)
{
    int x, y;
    extendedGcd(a,b,&x,&y);

    return (a * x) + (b * y);
}

std::string RSA::encrypt(std::string plaintext)
{
    std::vector<int> vec = getVec(plaintext);
    std::vector<int> encrypt;
    std::string ciphertext = "";
    int c, a, b;

    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        c = (int)(pow(*it, e)) % n;
        std::cout << *it<<"^"<<e<<"mod"<<n<<"="<<c<<'\n';
        encrypt.push_back(c);
    }

    for(std::vector<int>::iterator it = encrypt.begin(); it != encrypt.end(); ++it)
    {
        splitBlock(*it, &a, &b);
        ciphertext += (char)a + (char)b;
    }

    return ciphertext;
}

std::string RSA::decrypt(std::string ciphertext)
{
    std::vector<int> vec = getVec(ciphertext);
    std::vector<int> decrypt;
    std::string plaintext = "";
    int m, a, b;

    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        m = (int)(pow(*it, d)) % n;
        std::cout << *it<<"^"<<d<<"mod"<<n<<"="<<m<< '\n';
        decrypt.push_back(m);
    }

    for(std::vector<int>::iterator it = decrypt.begin(); it != decrypt.end(); ++it)
    {
        splitBlock(*it, &a, &b);
        plaintext += (char)a + (char)b;
    }

    return plaintext;
}

std::vector<int> RSA::getVec(std::string text)
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
