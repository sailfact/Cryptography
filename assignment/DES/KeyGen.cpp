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
///
/// KeyGen::insertKey
/// inserts a new key into keys
/// at the given index
///
void KeyGen::insertKey(int index, bitset<48> newKey)
{
    keys.insert(newKey, index);
}
///
/// KeyGen::addKey
/// adds a new key to the keys vector
/// increments count
///
void KeyGen::addKey(bitset<48> newKey)
{
    keys[count] = newKey;
    count ++;
}
///
/// KeyGen::getKey
/// returns the key corresponding to
/// the index given
///
bitset<48> KeyGen::getKey(int index)
{
    return keys.at(index);
}
///
/// KeyGen::generate
/// main function for the KeyGen class
/// generates the 16 keys needed by des
///
void KeyGen::generate(bitset<64> key)
{

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

    for (int i = 0; i < 56; i++)
    {
        newKey += key[DROPTABLE[i]-1];
    }

    return bitset<56> (newKey);
}
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
        newKey += key[DBOX[i]-1];
    }

    return bitset<48> (newKey);
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
    string keystr = key.to_string();

    left = bitset<28>(keystr.substr(0, keystr.length/2-1));
    right = bitset<28>(keystr.substr(keystr.length/2, keystr.length-1));
}
///
/// KeyGen::combine
/// joins the left and right key
/// returns the key
///
bitset<56> KeyGen::combine()
{
    string keystr = "";
    for (int i = 0; i < 28; i++)
    {
        keystr += left[i]
    }

    for (int i = 0; i < 28; i++)
    {
        keystr += right[i]
    }

    return bitset<56>(keystr);
}
