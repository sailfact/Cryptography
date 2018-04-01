#include "Affine.h"
#include "IO.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 17, b = 10;
    Affine cipher(a,b);
    IO io("infile.txt", "outfile.txt");

    string plaintext = io.readFile();
    string ciphertext = cipher.encrypt(plaintext);
    io.writeFile(cipher.decrypt(ciphertext));

    return 0;
}
