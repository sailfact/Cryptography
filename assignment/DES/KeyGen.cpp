#include "KeyGen.h"

KeyGen::KeyGen(bitset<10> key)
{
    cout << key << endl;
    generate(key.to_string());
}

string KeyGen::getKeyOne()
{
    return keyOne;
}

string KeyGen::getKeyTwo()
{
    return keyTwo;
}

void KeyGen::generate(string key)
{
    cout << key << endl;
    key = permutate10(key);
    key = leftShift(key);
    keyOne = permutate8(key);
    key = leftShift(leftShift(key)); // shift twice
    keyTwo = permutate8(key);
}

string KeyGen::permutate10(string key)
{
    string newKey = "";
    for (int i = 0; i < 10; i++)
    {
        cout << P10[i]-1;
        newKey +=  key[P10[i]-1];
    }

    cout << "P10 \t" << newKey << endl;

    return newKey;
}

string KeyGen::permutate8(string key)
{   
    string newKey = "";
    for (int i = 0; i < 8; i++)
    {
        newKey += key[P8[i]];
    }

    cout << "P8 \t" << newKey << endl;

    return newKey;
}

string KeyGen::leftShift(string inkey)
{
    string output = "";
    // shift left
    for (int i = 1; i <inkey.size() / 2; i ++) 
    {
        if (inkey.size() > i)
        {
            output += inkey[i];
        }
    }
    if(inkey.size() > 0)
    {
        output += inkey[0];
    }

    // right shift
    for(int i = inkey.size()/2; i < inkey.size(); i++)
    {
        if(inkey.size() > i)
        {
            output += inkey[i];
        }
    }
    if(inkey.size() > 0)
    {
        output += inkey[0];
    }

    return string(output);
}



