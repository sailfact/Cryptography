#include <iostream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

#define THRESH 20
typedef unsigned long long int u64;

class RSA
{
public:
    RSA();
    RSA(int, int);
    int extendedGcd(int , int , int *, int *);
    bool isPrime(int, int);
    int joinBlock(int, int);
    void splitBlock(u64, u64 *, u64 *);
    u64 findE(u64);
    u64 findD(int ,int);
    std::string encrypt(std::string);
    std::string decrypt(std::string);
    std::vector<int> getEncryptVec(std::string);
    std::vector<int> getDecryptVec(std::string);
    u64 calcExp(u64, u64, u64);
private:
    u64 p;
    u64 q;
    u64 e;
    u64 n;
    u64 phi;
    u64 d;
};
