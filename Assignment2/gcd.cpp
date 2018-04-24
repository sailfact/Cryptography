#include <iostream>
#include <cstdlib>

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main(int argc, char const *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (gcd(a, b))
        std::cout << a << " : " << b << " are Co-prime" << std::endl;
    else
        std::cout << a << " : " << b << " are NOT Co-prime" << std::endl;
    return 0;
}
