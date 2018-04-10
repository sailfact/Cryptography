#ifndef _AFFINE_H
#define _AFFINE_H
#include <iostream>
#include <string>
#include "IO.h"

#define ALPHASIZE 26
#define UPPER 65
#define LOWER 97

using namespace std;

class Affine
{
    public:
        Affine(int a, int b);
        string encrypt(string plaintxt);
        string decrypt(string ciphertxt);
        int findInverse();

    private:
        int a;
        int b;
};
#endif 