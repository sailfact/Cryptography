#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>

#define THRESH 6

class RSA
{
public:
    RSA(int, int);
    int extendedGcd(int , int , int *, int *);
    bool isPrime(int, int);
    int joinBlock(int, int);
    int splitBlock(int, int *, int *);
    int findE(int, int);
    int findD(int a,int b, int e);
    std::string encrypt(std::string);
    std::string decrypt(std::string);
    std::vector<int> getVec(std::string text);
private:
    int p;
    int q;
    int e;
    int n;
    int eulerTotient;
    int d;
};
