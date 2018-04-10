#include "KeyGen.h"

KeyGen::KeyGen(bitset<56> key)
{
    generate(key);
}

bitset<48> KeyGen::getKey(int index)
{
    return keys.at(index);
}

void KeyGen::generate(bitset<56> key)
{
    key = permutate56(key);
    key = leftShift(key);
    keys[count] = permutate48(key);
    count++;
    key = leftShift(leftShift(key)); // shift twice
    key[count] = permutate48(key);
}

bitset<56> KeyGen::permutate56(bitset<10> key)
{
    bitset<10> newKey;
    for (int i = 0; i < 10; i++)
    {
        newKey[i] = key[P10[i]-1];
    }

    cout << "P10 \t" << newKey << endl;

    return newKey;
}

bitset<48> KeyGen::permutate48(bitset<10> key)
{   
    bitset<48> newKey;
    for (int i = 0; i < 48; i++)
    {
        newKey[i] = key[P8[i]-1];
    }

    cout << "P8 \t" << newKey << endl;

    return newKey;
}

bitset<56> KeyGen::leftShift(bitset<10> inkey)
{
    bitset<5> left(10101);
    bitset<5> right(01001);
    left =  left<<1 | left >>4;
    right = right<<1 | right >>5;
}