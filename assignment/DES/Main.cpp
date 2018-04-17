<<<<<<< HEAD
=======
#include "KeyGen.h"
#include "IO.h"
#include "DES.h"

int main()
{
    KeyGen kg("11100001100110010101010111111010101011001100111100011110");

    for (int i = 0; i < 16; i++)
        std::cout << kg.getKey(i) << std::endl;

    return 0;
}
>>>>>>> 225b7567206d0bb3839421bf93a0fc19920fb1a8
