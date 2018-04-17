#include "KeyGen.h"
#include "IO.h"
#include "DES.h"

int main()
{
    KeyGen kg(984683372);

    for (int i = 0; i < 16; i++)
        std::cout << kg.getKey(i) << std::endl;

    return 0;
}
