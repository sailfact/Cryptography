#include "KeyGen.h"
///
/// KeyGen::KeyGen
/// constructor for KeyGen
/// calls starting function generate
///
KeyGen::KeyGen(bitset<64> key)
{
    cout << "constructor" << endl;
    this->count = 0;
    generate(key);
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
    return keys[index];
}
///
/// KeyGen::generate
/// main function for the KeyGen class
/// generates the 16 keys needed by des
///
void KeyGen::generate(bitset<64> key)
{
    cout << "generate" << endl;
    bitset<56> cipherKey = permute56(key);
    split(cipherKey);
    bitset<48> tempKey;
    for (int round = 0; round < 16; round++)
    {
        leftShift(round);
        tempKey = permute48(combine());
        addKey(tempKey);
    }
}
///
/// KeyGen:: permute56
/// permutes a given 64 bit key by removing
/// the parity bits with DROPTABLE
///table and returns a new 56 bit key
///
bitset<56> KeyGen::permute56(bitset<64> key)
{
    cout << "p56" << endl;
    string newKey = "";
    string strKey = key.to_string();

    for (int i = 0; i < 56; i++)
    {
        newKey += strKey.at(DROPTABLE[i]-1);
        std::cout << newKey << '\n';
    }
    std::cout << newKey << '\n';
    return bitset<56> (newKey);
}
///
/// KeyGen:: permute48
/// permutes a given 56 bit key
/// with DBOX table and returns a new
/// 48 bit key
///
bitset<48> KeyGen::permute48(bitset<56> key)
{
    cout << "p48" << endl;
    string newKey = "";
    string strKey = key.to_string();

    for (int i = 0; i < 48; i++)
    {
        newKey += strKey.at(DBOX[i]-1);
    }

    return bitset<48> (newKey);
}
///
/// KeyGen::leftShift
/// gets the current shift value from the SHIFT table
/// applys left shift to left and right keys
///
void KeyGen::leftShift(int round)
{
    cout << "ls" << endl;
    int shift = SHIFT[round];   // get the shift amount

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
    cout << "split" << endl;
    string keystr = key.to_string();

    left = bitset<28>(keystr.substr(0, keystr.length()/2-1));
    right = bitset<28>(keystr.substr(keystr.length()/2, keystr.length()-1));
}
///
/// KeyGen::combine
/// joins the left and right key
/// returns the key
///
bitset<56> KeyGen::combine()
{
    cout << "combine" << endl;
    string keystr = "";
    string l = left.to_string();
    string r = right.to_string();
    for (int i = 0; i < 28; i++)
    {
        keystr += l.at(i);
    }

    for (int i = 0; i < 28; i++)
    {
        keystr += r.at(i);
    }

    return bitset<56>(keystr);
}
