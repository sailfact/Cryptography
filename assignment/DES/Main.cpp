#include "KeyGen.h"
#include "IO.h"
#include "DES.h"

int main()
{
    KeyGen kg(1001111100);

    std::cout << kg.getKeyOne() << std::endl;
    std::cout << kg.getKeyTwo() << std::endl;

    return 0;
}
