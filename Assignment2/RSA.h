#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>

#define THRESH 6

class RSA
{
public:
    RSA();
    RSA(int, int);
    int extendedGcd(int , int , int *, int *);
    bool isPrime(int, int);
    int joinBlock(int, int);
    void splitBlock(long, long *, long *);
    long findE(long);
    long findD(int ,int);
    std::string encrypt(std::string);
    std::string decrypt(std::string);
    std::vector<int> getVec(std::string);
    long calcExp(long, long, long);
private:
    long p;
    long q;
    long e;
    long n;
    long phi;
    long d;
};
