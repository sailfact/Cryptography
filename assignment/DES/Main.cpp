#include "DES.h"
#include "IO.h"

int main()
{
    DES des;
    cout << des.encrypt("Hello");

    return 0;
}