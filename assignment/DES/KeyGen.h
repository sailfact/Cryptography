#ifndef _KEYGEN_H
#define _KEYGEN_H
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
// Keeps track of shift amount for each round
const static int SHIFT[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
// used for permuting the keys
const static int DBOX[48] = {
    14,17,11,24, 1, 5, 3,28,
    15, 6,21,10,23,19,12, 4,
    26, 8,16, 7,27,20,13, 2,
    41,52,31,37,47,55,30,40,
    51,45,33,48,44,49,39,56,
    34,53,46,42,50,36,29,32
};
// used for permuting the initial 64 bit key
const static int DROPTABLE[56] = {
    57,49,41,33,25,17, 9, 1,
    58,50,42,34,26,18,10, 2,
    59,51,43,35,27,19,11, 3,
    60,52,44,36,63,55,47,39,
    31,23,15, 7,62,54,46,38,
    30,22,14, 6,61,53,45,37,
    29,21,13, 5,28,20,12,04
};

class KeyGen
{
    public:
        KeyGen();
        KeyGen(bitset<64> key);
        void split(bitset<56> key);
        bitset<56> combine();
        void leftShift(int round);
        bitset<56> permute56(bitset<64> key);
        bitset<48> permute48(bitset<56> key);
        void generate(bitset<64> key);
        void addKey(bitset<48> key);
        bitset<48> getKey(int index);
    private:
        bitset<48> keys[16];
        bitset<28> left;
        bitset<28> right;
        int count;  // keeps track of elements in
};
#endif
