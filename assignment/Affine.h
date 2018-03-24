#include <iostream>
#include <bitset>
#include "IO.h"

using namespace std;

class Affine
{
    public:
        Affine();
        ~Affine();
        string encrypt(string text);
        string decrypt(string text);

    private:
        string plaintext;
        string ciphertext;
}
