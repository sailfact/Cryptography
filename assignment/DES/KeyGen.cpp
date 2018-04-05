#include "KeyGen.h"

KeyGen::KeyGen(bitset<10> key)
{
    cout << key << endl;
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
    cout << key << endl;
    bitset<10> newKey;
    for (int i = 0; i < 10; i++)
    {
        newKey[i] = key[P10[i]];
    }

    cout << newKey << endl;
    return newKey;
}

bitset<8> KeyGen::permutate8(bitset<10> key)
{   
    cout << key <<endl;
    bitset<8> newKey;
    for (int i = 0; i < 8; i++)
    {
        key[i] = newKey[P8[i]];
    }

    cout << newKey << endl;
    return newKey;
}

bitset<10> KeyGen::leftShift(bitset<10> key, int shift)
{
    bitset<5> left;
    bitset<5> right;

    for (int i = 0; i < 5; i ++)
    {
        left[i] = key[i];
    }

    cout << left << endl;

    for (int i = 5; i < 10; i ++)
    {
        right[i] = key[i];
    }

    cout << right << endl;

    left << shift;
    right << shift;

    for (int i = 0; i < 5; i ++)
    {
        key[i] = left[i];
    }

    for (int i = 5; i < 10; i ++)
    {
        key[i] = right[i];
    }

    cout << key << endl;

    return key;
}



