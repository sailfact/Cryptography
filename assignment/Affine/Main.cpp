/// Main.cpp
#include "Affine.h"
#include "IO.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    const char *infile = argv[1];
    int a = atoi(argv[2]), b = atoi(argv[3]);
    try
    {
        Affine cipher(a,b);
        string plaintext = readFile(infile);   // read plaintext from infile
        string ciphertext = cipher.encrypt(plaintext); // encrypts plaintext
        writeFile(ciphertext, "encrypt.txt"); // write ciphertext to file

        ciphertext = readFile("encrypt.txt"); // read ciphertext from file
        plaintext = cipher.decrypt(ciphertext); // decrypts ciphertext
        writeFile(plaintext, "decrypt.txt"); // write plaintext to file
    }
    catch(const char* msg)
    {
        cerr << msg << endl;    // keys are invalid
    }

    return 0;
}
