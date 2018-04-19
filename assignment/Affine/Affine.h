#ifndef _AFFINE_H
#define _AFFINE_H
#include <iostream>
#include <string>
#include "IO.h"

#define ALPHASIZE 26
#define UPPER 65    //upper starts here in ascii
#define LOWER 97    //lower starts here in ascii

using namespace std;

class Affine
{
    public:
        Affine(int a, int b);
        string encrypt(string plaintxt);
        string decrypt(string ciphertxt);
        int findInverse();
        int gcd(int x, int y);

    private:
        int a;
        int b;
};
#endif
