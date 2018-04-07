#include "Affine.h"
#include "IO.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 3, b = 25;
    Affine cipher(a,b);
    IO io("infile.txt", "outfile.txt");

    string plaintext = io.readFile();
    string ciphertext = cipher.encrypt(plaintext);
    cout << ciphertext << endl;
    cout << cipher.decrypt(ciphertext) << endl;;

    return 0;
}
