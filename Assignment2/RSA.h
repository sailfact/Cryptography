#ifndef RSA_H
#define RAS_H
#include <iostream>
#include <cmath>

#define THRESH 6

class
{
public:
    RSA(int, int);
    int extendedGcd(int , int , int *, int *);
    bool isPrime(int, int);
    int convertToASCII(char);
    int joinBlock(int, int);
    char converToInt(int);
private:
    int eKey;
    int nKey;
    int dKey;
}

#endif
