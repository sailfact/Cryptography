#include "KeyGen.h"
///
/// KeyGen::KeyGen
/// constructor for KeyGen
/// calls starting function generate
///
KeyGen::KeyGen(bitset<64> key)
{
    cout << key << endl;
    generate(key.to_string());
}
<<<<<<< HEAD

string KeyGen::getKeyOne()
=======
///
/// KeyGen::insertKey
/// inserts a new key into keys
/// at the given index
///
void KeyGen::insertKey(int index, bitset<48> newKey)
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c
{
    keys.insert(newKey, index);
}
<<<<<<< HEAD

string KeyGen::getKeyTwo()
=======
///
/// KeyGen::addKey
/// adds a new key to the keys vector
/// increments count
///
void KeyGen::addKey(bitset<48> newKey)
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c
{
    keys[count] = newKey;
    count ++;
}

<<<<<<< HEAD
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
=======
bitset<48> KeyGen::getKey(int index)
{
    return keys.at(index);
}

void KeyGen::generate(bitset<64> key)
{
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c

}
///
/// KeyGen:: permute56
/// permutes a given 64 bit key by removing
/// the parity bits with DROPTABLE
///table and returns a new 56 bit key
///
bitset<56> KeyGen::permute56(bitset<64> key)
{
    string newKey = "";

<<<<<<< HEAD
string KeyGen::permutate8(string key)
{   
    string newKey = "";
    for (int i = 0; i < 8; i++)
    {
        newKey += key[P8[i]];
=======
    for (int i = 0; i < 56; i++)
    {
        newKey[i] = key[DROPTABLE[i]-1];
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c
    }

    return bitset<56> (newKey);
}
<<<<<<< HEAD

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
=======
///
/// KeyGen:: permute48
/// permutes a given 56 bit key
/// with DBOX table and returns a new
/// 48 bit key
///
bitset<48> KeyGen::permute48(bitset<56> key);
{
    string newKey = "";

    for (int i = 0; i < 48; i++)
    {
        newKey[i] = key[DBOX[i]-1];
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c
    }
    if(inkey.size() > 0)
    {
        output += inkey[0];
    }

<<<<<<< HEAD
    return string(output);
=======
    return bitset<48> (newKey);
>>>>>>> 336bd0af0888acf6dde7d0d6bf61b2ade59a706c
}
///
/// KeyGen::leftShift
/// gets the current shift value from the SHIFT table
/// applys left shift to left and right keys
///
void KeyGen::leftShift()
{
    int shift = SHIFT[round];   // get the shift amount
    round ++;   // increment shift round

    left = left<<shift | left>>(left.size()-shift);
    right = right<<shift | right>>(right.size()-shift);
}
///
/// KeyGen::split
/// takes a 56 bit key
/// splits it into a left and right key
///
void KeyGen::split(bitset<56> key)
{

}
///
/// KeyGen::combine
/// joins the left and right key
/// returns the key
///
bitset<56> KeyGen::combine()
{

}
