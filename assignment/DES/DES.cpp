#include "DES.h"

DES::DES(string plaintext)
{
    plainBlock = bitset<64>(plaintext);
<<<<<<< HEAD
    keys = KeyGen("0/?2");
=======
    keys = KeyGen(10290129219);
>>>>>>> 225b7567206d0bb3839421bf93a0fc19920fb1a8
}

void DES::cipher()
{
    initialPermute();
    split();
    for (int round = 0; round < 16; round ++)
    {
        mixer(keys.getKey(round));
        if (round < 16)
        {
            swapper();
        }
    }
    combine();
    finalPermute();
}

void DES::initialPermute()
{
    string newBlock = "";
    string strBlock = plainBlock.to_string();

    for (int i = 0; i < 64; i++)
    {
        newBlock += strBlock.at(IP[i]-1);
    }
    plainBlock = bitset<64> (newBlock);
}

void DES::finalPermute()
{
    string newBlock = "";
    string strKey = cipherBlock.to_string();

    for (int i = 0; i < 64; i++)
    {
        newBlock += strKey.at(FP[i]-1);
    }
    cipherBlock = bitset<64> (newBlock);
}

void DES::split()
{
    string blockstr = plainBlock.to_string();

    leftBlock = bitset<32>(blockstr.substr(0, blockstr.length()/2-1));
    rightBlock = bitset<32>(blockstr.substr(blockstr.length()/2, blockstr.length()-1));
}

void DES::combine()
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

    cipherBlock = bitset<64>(blockstr);
}

void DES::mixer(bitset<48> key)
{
    bitset<32> temp1 = rightBlock;
    bitset<32> temp2 = function(temp1, key);
    bitset<32> temp3 = exclusiveOr32(leftBlock, temp2);
    rightBlock = temp3;
}
bitset<32> DES::function(bitset<32> block, bitset<48> key)
{
    bitset<48> temp1 = permuteExpansion(block);
    bitset<48> temp2 = exclusiveOr48(temp1, key);
    bitset<48> temp3 = substitute(temp2);
    return permuteStraight(temp3);
}

<<<<<<< HEAD
bitset<32> DES::substitute(bitset<48> block)
{
    int row, col;
    string strBlock = block.to_string();
=======
bitset<48> DES::substitute(bitset<48> block)
{
>>>>>>> 225b7567206d0bb3839421bf93a0fc19920fb1a8
    for (int i = 0; i < 8; i++)
    {
        
    }
}

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

bitset<32> DES::permuteStraight(bitset<48> block)
{
    string newBlock = "";
    string strBlock = block.to_string();

    for (int i = 0; i < 32; i++)
    {
        newBlock += strBlock.at(STRAIGHT[i]-1);
    }

    return bitset<32> (newBlock);
}
