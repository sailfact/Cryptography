/// Affine.cpp
#include "Affine.h"
///
/// Affine::Affine
/// Constructor for Affine
/// assigns a and b keys
/// and checks their validity
Affine::Affine(int a, int b)
{
    // check if a and b are valid yet
    // a must be positive and co-prime with 26
    // b must be between 1 and 25 inclusive
    if ((a >= 0)&&(b <= 25)&&(b >= 0)&&gcd(a, ALPHASIZE)==1)
    {
        this->a = a;
        this->b = b;
    }
    else
    {
        throw "Error: Invalid Keys!!!";
    }
}
///
/// Affine::encrypt
/// encrypts a given string using the affine cipher
/// E(x)=(ax+b) mod 26
string Affine::encrypt(string plaintxt)
{
    string ciphertxt = "";
    for (int i = 0; i < plaintxt.size(); i++)
    {
        if (isalpha(plaintxt[i]))
        {
            //E(x)=(ax+b) mod 26
            if (isupper(plaintxt[i]))
                ciphertxt += (char)(int(((a * (plaintxt[i]-UPPER) + b) % ALPHASIZE) + UPPER));
            else
                ciphertxt += (char)(int(((a * (plaintxt[i]-LOWER) + b) % ALPHASIZE) + LOWER));
        }
        else    // if it's net a letter add it anyway
        {
            ciphertxt += plaintxt[i];
        }
    }

    return ciphertxt;
}
///
/// Affine::decrypt
/// decrypts a given string using the affine cipher
/// D(x)=a^-1(x-b) mod 26
string Affine::decrypt(string ciphertxt)
{
    string plaintxt = "";
    int aInv = findInverse();   // get a inverse

    for (int i = 0; i < ciphertxt.size(); i ++)
    {
        if (isalpha(ciphertxt[i]))
        {
            if(isupper(ciphertxt[i]))
                plaintxt += (char)(int(aInv * (ALPHASIZE + ciphertxt[i] - UPPER - b) % ALPHASIZE + UPPER));
            else
                plaintxt += (char)(int(aInv * (ALPHASIZE + ciphertxt[i] - LOWER - b) % ALPHASIZE + LOWER));
        }
        else    // if it's not a letter add it anyway
        {
            plaintxt += ciphertxt[i];
        }
    }

    return plaintxt;
}
///
/// Affine::findInverse
/// finds the multiplicitive inverse of key a
int Affine::findInverse()
{
    int inv = 0;
    for (int i = 0; i < ALPHASIZE; i++)
    {
        if ((a*i)%ALPHASIZE==1)
        {
            inv = i;
        }
    }

    return inv;
}
///
/// Affine::gcd
/// returns the greates common divisor
/// for x and y
int Affine::gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
