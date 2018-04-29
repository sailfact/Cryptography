#include "RSA.h"
#include "IO.h"
#include <cstdlib>

int main(int argc, char const *argv[])
{
    int p, q;
    if (argc > 1)
    {
        const char * infile = argv[1];
        if (argc == 3)
        {
            p = atoi(argv[2]);
            q = atoi(argv[3]);
        }
        else    // if user doesn't enter primes assign default ones
        {
            p = 20011;
            q = 50021;
        }

        std::string plaintext = readFile(infile);
    }
    else
        std::cerr << "ERROR : Not enough arguments" << std::endl;

    return 0;
}
