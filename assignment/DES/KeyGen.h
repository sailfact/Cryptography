#ifndef KEYGEN_H
#define KEYGEN_H
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const static int SHIFT[16] = {1, 1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
const static int DBOX[48] = {
    14,17,11,24, 1, 5, 3,28,
    15, 6,21,10,23,19,12, 4,
    26, 8,16, 7,27,20,13, 2,
    41,52,31,37,47,55,30,40,
    51,45,33,48,44,49,39,56,
    34,53,46,42,50,36,29,32
};

class KeyGen
{
    public:
        KeyGen(bitset<64> key);
        void split(bitset<56> key);
        bitset<48> combine();
        bitset<28> leftShift(bitset<28> inKey);
        bitset<56> permute(bitset<64> key);
        void generate(bitset<64> key);
        void KeyGen::insertKey(int index, bitset<48> newKey);
        void addKey(bitset<48> key);
        bitset<48> getKey(int index);
    private:
        vector<bitset<48>> keys;
        bitset<28> left;
        bitset<28> right;
        int count = 0;
        int round = 0;
};
#endif
