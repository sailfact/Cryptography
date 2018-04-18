#include "DES.h"
///
/// DES::DES
///
DES::DES()
{
    keys = KeyGen(973846494795);
}

string DES::encrypt(string plaintext)
{
    string block = "";
    string ciphertext = "";
    int blockCount = 1;
    for (int i = 0; i < plaintext.length(); i ++)
    {
        block += bitset<8>(plaintext[i]).to_string();  
        if (blockCount == 8)
        {
            ciphertext += cipher(bitset<64>(block), keys).to_string();
            blockCount = 1;
        }
        else if (i == plaintext.length() -1 && blockCount != 8)
        {
            // pad block with 0's
            for (int j = 0; j < blockCount; j++)
            {
                block +='0';
            }
            ciphertext += cipher(bitset<64>(block), keys).to_string();
        }
        blockCount++;
    }

    return ciphertext;
}

string DES::decrypt(string ciphertext)
{

}
///
/// DES::cipher
///
bitset<64> DES::cipher(bitset<64> inBlock, KeyGen keys)
{
    bitset<64> outBlock;
    inBlock = initialPermute(inBlock);
    split(inBlock);
    for (int round = 0; round < 16; round ++)
    {
        mixer(keys.getKey(round));
        if (round < 16)
        {
            swapper();
        }
    }
    outBlock = combine();

    return finalPermute(outBlock);
}
///
/// DES::initialPermute
///
bitset<64> DES::initialPermute(bitset<64> inBlock)
{
    string newBlock = "";
    string strBlock = inBlock.to_string();

    for (int i = 0; i < 64; i++)
    {
        newBlock += strBlock.at(IP[i]-1);
    }
    return bitset<64> (newBlock);
}
///
/// DES::finalPermute
///
bitset<64> DES::finalPermute(bitset<64> inBlock)
{
    string newBlock = "";
    string strKey = inBlock.to_string();

    for (int i = 0; i < 64; i++)
    {
        newBlock += strKey.at(FP[i]-1);
    }
    return  bitset<64> (newBlock);
}
///
/// DES::split
///
void DES::split(bitset<64> inBlock)
{
    string blockstr = inBlock.to_string();

    leftBlock = bitset<32>(blockstr.substr(0, 32));
    rightBlock = bitset<32>(blockstr.substr(32, 32));
}
///
/// DES::combine
///
bitset<64> DES::combine()
{
    string blockstr = "";
    string l = leftBlock.to_string();
    string r = rightBlock.to_string();
    for (int i = 0; i < 32; i++)
    {
        blockstr += l.at(i);
    }

    for (int i = 0; i < 32; i++)
    {
        blockstr += r.at(i);
    }

    return bitset<64>(blockstr);
}
///
/// DES::mixer
///
void DES::mixer(bitset<48> key)
{
    bitset<32> temp1 = rightBlock;
    bitset<32> temp2 = function(temp1, key);
    bitset<32> temp3 = exclusiveOr32(leftBlock, temp2);
    rightBlock = temp3;
}

void DES::swapper()
{
    bitset<32> temp = leftBlock;
    leftBlock = rightBlock;
    rightBlock = temp;
}
///
/// DES::function
///
bitset<32> DES::function(bitset<32> block, bitset<48> key)
{
    bitset<48> temp1 = permuteExpansion(block);
    bitset<48> temp2 = exclusiveOr48(temp1, key);
    bitset<32> temp3 = substitute(temp2);
    return permuteStraight(temp3);
}
///
/// DES::substitute
///
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

    return bitset<32>(strBlock);
}
///
/// DES::sub
///
bitset<4> DES::sub(string subBlock, int box)
{
    int row = bitset<2>(subBlock.substr(0,1) + subBlock.substr(5,1)).to_ulong();
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
///
bitset<48> DES::permuteExpansion(bitset<32> block)
{
    string newBlock = "";
    string strBlock = block.to_string();

    for (int i = 0; i < 48; i++)
    {
        newBlock += strBlock.at(EXPANSION[i]-1);
    }

    return bitset<48> (newBlock);
}
///
/// DES::permuteStraight
///
bitset<32> DES::permuteStraight(bitset<32> block)
{
    string newBlock = "";
    string strBlock = block.to_string();

    for (int i = 0; i < 32; i++)
    {
        newBlock += strBlock.at(STRAIGHT[i]-1);
    }

    return bitset<32> (newBlock);
}

bitset<32> DES::exclusiveOr32(bitset<32> blockOne, bitset<32> blockTwo)
{
    return blockOne ^= blockTwo;
}

bitset<48> DES::exclusiveOr48(bitset<48> blockOne, bitset<48> blockTwo)
{
    return blockOne ^= blockTwo;
}
