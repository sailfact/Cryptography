#ifndef KEYGEN_H
#define KEYGEN_H
#include <iostream>
#include <bitset>

using namespace std;

const static int P10[] = {3,5,2,7,4,10,1,9,8,6};
const static int P8[] = {6,3,7,4,8,5,10,9}; 

class KeyGen
{
    public:
        KeyGen(bitset<10> key);
        string leftShift(string);
        string permutate10(string key);
        string permutate8(string key);
        void generate(string key);
        string getKeyOne();
        string getKeyTwo();  
    private:
        string keyOne;
        string keyTwo;
};
#endif