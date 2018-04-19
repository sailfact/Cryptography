/// DES.cpp
#include "DES.h"
///
/// DES::DES
DES::DES(KeyGen k1, KeyGen k2)
{
    this->keys = k1;
    this->invKeys = k2;
}
///
/// DES::encrypt
/// takes a string and encrypts 64 bit blocks at a
/// time with des cipher
string DES::encrypt(string plaintext)
{
    string block = "";
    string ciphertext = "";
    int blockCount = 1;
    for (int i = 0; i < plaintext.length(); i ++)
    {
        block += bitset<8>(plaintext[i]).to_string(); // add char to block
        if (blockCount == 8)    // if block is size 8
        {
            // cipher next 64 bit block
            ciphertext += convertBack(cipher(bitset<64>(block), keys).to_string());
            blockCount = 1;
        }
        else if (i == plaintext.length() -1 && blockCount != 8)
        {
            // pad block with 0's if not 64 bits
            for (int j = 0; j < blockCount; j++)
            {
                block +='0';
            }
            // cipher last block
            ciphertext += convertBack(cipher(bitset<64>(block), keys).to_string());
        }
        blockCount++;
    }

    return ciphertext;
}
///
/// DES::decrypt
/// takes a string and decrypts 64 bit blocks at a
/// time with des cipher
string DES::decrypt(string ciphertext)
{
    string block = "";
    string plaintext = "";
    int blockCount = 1;
    for (int i = 0; i < ciphertext.length(); i ++)
    {
        block += bitset<8>(ciphertext[i]).to_string();// add char to block
        if (blockCount == 8)// if block is size 8
        {
            // cipher next 64 bit block
            plaintext += convertBack(cipher(bitset<64>(block), invKeys).to_string());
            blockCount = 1;
        }
        else if (i == ciphertext.length() -1 && blockCount != 8)
        {
            // pad block with 0's if not 64 bits
            for (int j = 0; j < blockCount; j++)
            {
                block +='0';
            }
            // cipher last block
            plaintext += convertBack(cipher(bitset<64>(block), keys).to_string());
        }
        blockCount++;
    }

    return plaintext;
}
///
/// DES::cipher
/// takes a 64 bit block and a set of keys and ciphers it
bitset<64> DES::cipher(bitset<64> inBlock, KeyGen keys)
{
    bitset<64> outBlock;
    inBlock = initialPermute(inBlock);  // !P
    split(inBlock); // split block into left and right block
    for (int round = 0; round < 16; round ++)
    {
        fk(keys.getKey(round)); //fiestel function
        if (round < 16)
        {
            swapper();  // switch left and right block
        }
    }
    outBlock = combine();

    return finalPermute(outBlock);  // IP-1
}
///
/// DES::initialPermute
/// permutes the block with the IP table
bitset<64> DES::initialPermute(bitset<64> inBlock)
{
    string newBlock = "";
    string strBlock = inBlock.to_string();

    for (int i = 0; i < 64; i++)
    {
        newBlock += strBlock[IP[i]-1];
    }
    return bitset<64> (newBlock);
}
///
/// DES::finalPermute
/// permutes the block with the FP table
bitset<64> DES::finalPermute(bitset<64> inBlock)
{
    string newBlock = "";
    string strKey = inBlock.to_string();

    for (int i = 0; i < 64; i++)
    {
        newBlock += strKey[FP[i]-1];
    }
    return  bitset<64> (newBlock);
}
///
/// DES::split
/// splits a given block and assigns each half to
/// fields left and right block
void DES::split(bitset<64> inBlock)
{
    string blockstr = inBlock.to_string();

    leftBlock = bitset<32>(blockstr.substr(0, 32));
    rightBlock = bitset<32>(blockstr.substr(32, 32));
}
///
/// DES::combine
/// returns the left and right block as one whole block
bitset<64> DES::combine()
{
    string blockstr = "";
    string l = leftBlock.to_string();
    string r = rightBlock.to_string();
    // assign left to block
    for (int i = 0; i < 32; i++)
    {
        blockstr += l[i];
    }
    // assign right to block
    for (int i = 0; i < 32; i++)
    {
        blockstr += r[i];
    }

    return bitset<64>(blockstr);
}
///
/// DES::fk
/// fiestel function for des
void DES::fk(bitset<48> key)
{
    bitset<32> temp1 = rightBlock;  // assign righ block to temp1
    bitset<32> temp2 = F(temp1, key); // assign temp2 with F(R, key)
    bitset<32> temp3 = exclusiveOr32(leftBlock, temp2); // xor left and f(R, key)
    rightBlock = temp3; // assign temp3 back to right;
}
///
/// DES::swapper
/// switches the right block with the left block
void DES::swapper()
{
    bitset<32> temp = leftBlock;
    leftBlock = rightBlock;
    rightBlock = temp;
}
///
/// DES::F
/// F function
bitset<32> DES::F(bitset<32> block, bitset<48> key)
{
    bitset<48> temp1 = permuteExpansion(block); // expands the block
    bitset<48> temp2 = exclusiveOr48(temp1, key); // xors with key
    bitset<32> temp3 = substitute(temp2); // sub boxes
    return permuteStraight(temp3); // permute with straight table
}
///
/// DES::substitute
/// returns values from SBOX values for each 6 bits of the
/// 48 bit block
bitset<32> DES::substitute(bitset<48> block)
{
    string strBlock = block.to_string();
    string temp = "";
    temp += sub(strBlock.substr(0,6), 1).to_string();
    temp += sub(strBlock.substr(6,6), 2).to_string();
    temp += sub(strBlock.substr(12,6), 3).to_string();
    temp += sub(strBlock.substr(18,6), 4).to_string();
    temp += sub(strBlock.substr(24,6), 5).to_string();
    temp += sub(strBlock.substr(30,6), 6).to_string();
    temp += sub(strBlock.substr(36,6), 7).to_string();
    temp += sub(strBlock.substr(42,6), 8).to_string();

    return bitset<32>(temp);
}
///
/// DES::sub
/// takes a block and a flag indicating which SBOX to use
bitset<4> DES::sub(string subBlock, int box)
{
    // get end bits and convert to int
    int row = bitset<2>(subBlock.substr(0,1) + subBlock.substr(5,1)).to_ulong();
    // gets middle 4 bits and converts to int
    int col = bitset<4>(subBlock.substr(1,4)).to_ulong();
    int value = 0;
    switch (box)
    {
        case 1:
            value = S1[row][col];
            break;
        case 2:
            value = S2[row][col];
            break;
        case 3:
            value = S3[row][col];
            break;
        case 4:
            value = S4[row][col];
            break;
        case 5:
            value = S5[row][col];
            break;
        case 6:
            value = S6[row][col];
            break;
        case 7:
            value = S7[row][col];
            break;
        case 8:
            value = S8[row][col];
            break;
    }
    return bitset<4> (value);
}
///
/// DES::permuteExpansion
/// permutes a block with the EXPANSION table
bitset<48> DES::permuteExpansion(bitset<32> block)
{
    string newBlock = "";
    string strBlock = block.to_string();

    for (int i = 0; i < 48; i++)
    {
        newBlock += strBlock[EXPANSION[i]-1];
    }
    return bitset<48> (newBlock);
}
///
/// DES::permuteStraight
/// permutes the block with the STRAIGHT table
bitset<32> DES::permuteStraight(bitset<32> block)
{
    string newBlock = "";
    string strBlock = block.to_string();

    for (int i = 0; i < 32; i++)
    {
        newBlock += strBlock[STRAIGHT[i]-1];
    }
    return bitset<32> (newBlock);
}
///
/// DES::exclusiveOr32
/// XOR's to 32 bit block
bitset<32> DES::exclusiveOr32(bitset<32> blockOne, bitset<32> blockTwo)
{
    return blockOne ^= blockTwo;
}
///
/// DES::exclusiveOr48
/// XOR's to 48 bit block
bitset<48> DES::exclusiveOr48(bitset<48> blockOne, bitset<48> blockTwo)
{
    return blockOne ^= blockTwo;
}
///
/// DES::convertBack
/// takes a string of binary and converts it back to ascii string
string DES::convertBack(string plaintext)
{
    stringstream sstream(plaintext);
    string output;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    return output;
}
