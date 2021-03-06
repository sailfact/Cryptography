/// Main.cpp
#include "RSA.h"
#include "IO.h"
#include <cstdlib>

int main(int argc, char const *argv[])
{
    int p, q;
    int option;
    if (argc > 1)
    {
        const char * infile = argv[1];
        if (argc == 4)  // get p and q from command line
        {
            p = atoi(argv[2]);     
            q = atoi(argv[3]);
        }
        else    // if user doesn't enter primes assign default ones
        {
            p = 20011;
            q = 50021;
        }
        try
        {
            RSA rsa(p,q);   // construct rsa with p and q
            std::string plaintext = "";
            std::string ciphertext = "";
            while (1)
            {
                std::cout << "Enter [1] to encrypt\nEnter [2] to decrypt\nEnter [3] to exit" << std::endl;
                std::cin >> option;
                switch(option)
                {
                    case 1: // encrypt
                        plaintext = readFile(infile);
                        ciphertext = rsa.encrypt(plaintext);
                        writeFile(ciphertext,"encrypt.txt");           
                        break;
                    case 2: // decrypt
                        ciphertext = readFile("encrypt.txt");
                        plaintext = rsa.decrypt(ciphertext);
                        writeFile(plaintext, "decrypt.txt");
                        break;
                    case 3:
                        exit(0);
                        break;
                    default:
                        break;
                }
            }
        }
        catch(const char* msg)  // if keys are incorrect print error
        {   
            std::cerr << msg << '\n';           
        }
    }
    else
        std::cerr << "ERROR : Not enough arguments" << std::endl;
    return 0;
}
