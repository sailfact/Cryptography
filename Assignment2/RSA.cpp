#include "RSA.h"

RSA::RSA(int e, int n)
{

    if ((e < n)&&(isPrime(e, THRESH) && isPrime(n, THRESH)))
    {
        this->eKey = e;
        this->nKey = n;
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
    int gcd = extendedGcd(b%a, &tempX, &tempY);

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

int RSA::convertToASCII(char c)
{
    return (int)c;
}

int  RSA::joinBlock(int a, int b)
{
    return (a * 1000) + b;
}

char RSA::converToInt(int i)
{
    return (char)i;
}
