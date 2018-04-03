#include "KeyGen.h"

KeyGen::KeyGen(bitset<10> key)
{
    generate(key);
}

bitset<8> KeyGen::getKeyOne()
{
    return keyOne;
}

bitset<8> KeyGen::getKeyTwo()
{
    return keyTwo;
}

void KeyGen::generate(bitset<10> key)
{
    bitset<10> newKey = permutate10(key);
    newKey = leftShift(newKey, 1);
    keyOne = permutate8(newKey);
    newKey = leftShift(newKey, 2);
    keyTwo = permutate8(newKey);
}

bitset<10> KeyGen::permutate10(bitset<10> key)
{
    bitset<10> ip = NULL;
    for (int i = 0; i < 10; i++)
    {
        ip[i] = key[P10[i]];
    }

    return ip;
}

bitset<8> KeyGen::permutate8(bitset<10> key)
{
    bitset<8> newKey = NULL;
    for (int i = 0; i < 8; i++)
    {
        key[i] = newKey[P8[i]];
    }

    return newKey;
}

bitset<10> KeyGen::leftShift(bitset<10> key, int shift)
{
    bitset<5> left;
    bitset<5> right;
}



