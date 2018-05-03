/// Main.cpp
#include "DES.h"
#include "IO.h"

int main(int argc, const char **argv)
{
    string str = "0001001100110100-s--010101110111100110011011101111001101111111110001";
    KeyGen keys;
    keys = KeyGen(bitset<64>(str));
    for (int i  = 0; i < 16; i++)
    {
        cout << keys.getKey(i) << endl;  
    }
    KeyGen ikeys = keys.invertKeys();
    DES des(keys, ikeys);
    const char* infile = argv[1];
    string plaintext = readFile(infile);    // get text from file
    string ciphertext = des.encrypt(plaintext); // encrypt the text
    writeFile(ciphertext, "encrypt.txt");   // write text to a file
    // clear the strings
    ciphertext = "";
    plaintext = "";

    ciphertext = readFile("encrypt.txt");   // read text back
    plaintext = des.decrypt(ciphertext);    // decrypt the text
    writeFile(plaintext, "decrypt.txt");    // write the decrypted text to a file

    return 0;
}
