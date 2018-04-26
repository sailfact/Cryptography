#include "RSA.h"
#include "IO.h"

int main(int argc, char const *argv[])
{
    int e, n;
    if (argc > 1)
    {
        const char * infile = argv[1];
        if (argc == 3)
        {
            e = atoi(argv[2]);
            n = atoi(argv[3]);
        }
        else    // if user doesn't enter primes assign default ones
        {
            e = 20011;
            n = 50021;
        }

        string plaintext = readFile(infile);
    }
    else
        std::cerr << "ERROR : Not enough arguments" << std::endl;

    return 0;
}
