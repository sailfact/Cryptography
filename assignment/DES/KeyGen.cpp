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
    key = permutate10(key);
    key = leftShift(key);
    keyOne = permutate8(key);
    key = leftShift(leftShift(key)); // shift twice
    keyTwo = permutate8(key);
}

bitset<10> KeyGen::permutate10(bitset<10> key)
{
    bitset<10> newKey;
    for (int i = 0; i < 10; i++)
    {
        newKey[i] = key[P10[i]-1];
    }

    cout << "P10 \t" << newKey << endl;

    return newKey;
}

bitset<8> KeyGen::permutate8(bitset<10> key)
{   
    bitset<8> newKey;
    for (int i = 0; i < 8; i++)
    {
        newKey[i] = key[P8[i]];
    }

    cout << "P8 \t" << newKey << endl;

    return newKey;
}

bitset<10> KeyGen::leftShift(bitset<10> inkey)
{
    string key = inkey.to_string();
    string output = "";
    // shift left
    for (int i = 1; i <key.size() / 2; i ++) 
    {
        if (key.size() > i)
        {
            output += key[i];
        }
    }

    // right shift
    for(int i = key.size()/2; i < key.size(); i++)
    {
        if(key.size() > i)
        {
            output += key[i];
        }
    }

    return bitset<10>(output);
}



