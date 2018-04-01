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
    for (int i = 0; i < plaintxt.length(); i++)
    {
        if (plaintxt[i] != ' ')
        {
            if (isupper(plaintxt[i]))
                ciphertxt += (char)((((a * plaintxt[i])+b)%ALPHASIZE)+UPPER);
            else 
                ciphertxt += (char)((((a * plaintxt[i])+b)%ALPHASIZE)+LOWER);
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

    for (int i = 0; i < ciphertxt.length(); i ++)
    {
        if (ciphertxt[i] != ' ')
        {
            if(isupper(ciphertxt[i]))
                plaintxt += (char)(((aInv*((ciphertxt[i] - b))%ALPHASIZE))+UPPER);
            else
                plaintxt += (char)(((aInv*((ciphertxt[i] - b))%ALPHASIZE))+LOWER);
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
        if ((a*i)%26==1)
        {
            inv = i;
        }
    }

    return inv;
}
