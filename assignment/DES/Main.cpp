#include "DES.h"
#include "IO.h"

int main(int argc, const char **argv)
{
    /*DES des(9455435345);
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
    */

    bitset<64> pt(121212121212);
    KeyGen keys(892765478632);
    DES des;
    KeyGen ikeys = keys.invertKeys();

    bitset<64> ec = des.cipher(pt, keys);
    bitset<64> dc = des.cipher(ec, ikeys);
    cout << pt << endl;
    cout << ec << endl;
    cout << dc << endl;
    return 0;
}
