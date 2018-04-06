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
        bitset<10> leftShift(bitset<10>);
        bitset<10> permutate10(bitset<10> key);
        bitset<8> permutate8(bitset<10> key);
        void generate(bitset<10> key);
        bitset<8> getKeyOne();
        bitset<8> getKeyTwo();  
    private:
        bitset<8> keyOne;
        bitset<8> keyTwo;
};
#endif