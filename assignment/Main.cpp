#include "Affine.h"
#include "IO.h"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
            string filename = argv[1];
            IO io = new IO(filename);
    }

    return 0;
}
