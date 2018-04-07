#ifndef DES_H
#define DES_H
#include "IO.h"
#include "KeyGen.h"
#include <bitset>

using namespace std;

class DES {
    public:
        DES();
        string IP(string plaintext);
        string IPInverse(string plaintext);
        void fk();
        string F(string input, string key);
        void SW();
    private:
        string plaintext;
        string left;
        string right;
        string ciphertext;
};
#endif