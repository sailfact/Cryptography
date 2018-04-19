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
        string plaintext = readFile(infile);
        string ciphertext = cipher.encrypt(plaintext);
        writeFile(ciphertext, "encrypt.txt");

        ciphertext = readFile("encrypt.txt");
        plaintext = cipher.decrypt(ciphertext);
        writeFile(plaintext, "decrypt.txt");
    }
    catch(const char* msg)
    {
        cerr << msg << endl;
    }

    return 0;
}
