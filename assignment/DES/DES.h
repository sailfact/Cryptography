#ifndef _DES_H
#define _DES_H
#include "KeyGen.h"
#include "SBOX.h"
#include <bitset>
#include <sstream>
///
/// DES.h
/// contains the class definition for des
/// and tables used for permutation
using namespace std;
// initial permutation
const static int IP[64] = {
    58,50,42,34,26,18,10, 2,
    60,52,44,36,28,20,12, 4,
    62,54,46,38,30,22,14, 6,
    64,56,48,40,32,24,16, 8,
    57,49,41,33,25,17, 9, 1,
    59,51,43,35,27,19,11, 3,
    61,53,45,37,29,21,13, 5,
    63,55,47,39,31,23,15, 7
};
// final permutation
const static int FP[64] = {
    40, 8,48,16,56,24,64,32,
    39, 7,47,15,55,23,63,31,
    38, 6,46,14,54,22,62,30,
    37, 5,45,13,53,21,61,29,
    36, 4,44,12,52,20,60,28,
    35, 3,43,11,51,19,59,27,
    34, 2,42,10,50,18,58,26,
    33, 1,41, 9,49,17,57,25
};
// expansion d-box
const static int EXPANSION[48] = {
    32, 1, 2, 3, 4, 5,
     4, 5, 6, 7, 8, 9,
     8, 9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32, 1
};
// straight permutation
const static int STRAIGHT[32] = {
    16, 7,20,21,29,12,28,17,
     1,15,23,26, 5,18,31,10,
     2, 8,24,14,32,27, 3, 9,
    19,13,30, 6,22,11, 4,25
};

class DES
{
    public:
        string encrypt(string plaintext,KeyGen keys);
        string decrypt(string ciphertext, KeyGen keys);
        bitset<64> cipher(bitset<64> inBlock, KeyGen keys);
        bitset<64> initialPermute(bitset<64> inBlock);
        bitset<64> finalPermute(bitset<64> inBlock);
        void split(bitset<64> block);
        bitset<64> combine();
        void mixer(bitset<48> key);
        void swapper();
        bitset<32> function(bitset<32> block, bitset<48> key);
        bitset<32> substitute(bitset<48> block);
        bitset<4> sub(string subBlock, int box);
        bitset<48> permuteExpansion(bitset<32> block);
        bitset<32> permuteStraight(bitset<32> block);
        bitset<32> exclusiveOr32(bitset<32> blockOne, bitset<32> blockTwo);
        bitset<48> exclusiveOr48(bitset<48> blockOne, bitset<48> blockTwo);
        string convertBack(string plaintext);

    private:
        KeyGen keys;
        bitset<32> leftBlock;
        bitset<32> rightBlock;
};
#endif
