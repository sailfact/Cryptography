#include "KeyGen.h"

KeyGen::KeyGen(bitset<64> key)
{
    generate(key);
}

void KeyGen::insertKey(int index, bitset<48> newKey)
{
    keys.insert(newKey, index);
}

void KeyGen::addKey(bitset<48> newKey)
{
    keys[count] = newKey;
    count ++;
}

bitset<48> KeyGen::getKey(int index)
{
    return keys.at(index);
}

void KeyGen::generate(bitset<64> key)
{

}

bitset<56> KeyGen::permute(bitset<64> key)
{

}

void KeyGen::leftShift()
{
    int shift = SHIFT[round];
    round ++;

    left = left<<shift | left>>(left.size()-shift);
    right = right<<shift | right>>(right.size()-shift);
}
