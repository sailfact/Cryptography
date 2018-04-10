#include "Affine.h"

Affine::Affine(int a, int b)
{
    // check if a and b are valid yet
    if ((a >= 0)&&(b <= 25))
    {
        this->a = a;
        this->b = b;
    }
    else
    {
        throw "Error: Invalid Keys!!!";
    }
}

string Affine::encrypt(string plaintxt)
{
    string ciphertxt = "";
    for (int i = 0; i < plaintxt.size(); i++)
    {
        if (plaintxt[i] != ' ')
        {
            if (isupper(plaintxt[i]))
                ciphertxt += (char)(int(((a * (plaintxt[i]-UPPER) + b) % ALPHASIZE) + UPPER));
            else 
                ciphertxt += (char)(int(((a * (plaintxt[i]-LOWER) + b) % ALPHASIZE) + LOWER));
        }
        else
        {
            ciphertxt += plaintxt[i];
        }
    }

    return ciphertxt;
}

string Affine::decrypt(string ciphertxt)
{
    string plaintxt = "";
    int aInv = findInverse();

    for (int i = 0; i < ciphertxt.size(); i ++)
    {
        if (isalpha(ciphertxt[i]))
        {
            if(isupper(ciphertxt[i]))
                plaintxt += (char)(int(aInv * (26 + ciphertxt[i] - UPPER - b) % 26 + UPPER));
            else
                plaintxt += (char)(int(aInv * (26 + ciphertxt[i] - LOWER - b) % 26 + LOWER));
        }
        else
        {
            plaintxt += ciphertxt[i];
        }
    }

    return plaintxt;
}

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
