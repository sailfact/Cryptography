#include "KeyGen.h"
#include "IO.h"
#include "DES.h"

int main()
{
    KeyGen kg(1100011110);

    std::cout << kg.getKeyOne() << std::endl;
    std::cout << kg.getKeyTwo() << std::endl;

    return 0;
}
