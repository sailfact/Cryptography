#include <iostream>
#include <bitset>
#include "KeyGen.h"

int main()
{
    KeyGen kg(1010110011);

    std::cout << kg.getKeyOne() << std::endl;
    std::cout << kg.getKeyTwo() << std::endl;

    return 0;
}
