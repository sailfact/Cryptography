#include "DES.h"
#include "IO.h"

int main(int argc, const char **argv)
{
    DES des(9455435345);
    const char* infile = argv[1];
    string plaintext = readFile(infile);
    string ciphertext = des.encrypt(plaintext);
    writeFile(ciphertext, "encrypt.txt");
    ciphertext = "";
    plaintext = "";

    ciphertext = readFile("encrypt.txt");
    plaintext = des.decrypt(ciphertext);
    writeFile(plaintext, "decrypt.txt");

    return 0;
}
