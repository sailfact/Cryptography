#include <iostream>
#include <cstdlib>
///
/// gcd
/// calculate the the greatest common divisor
/// recursively
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main(int argc, char const *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    std::cout << "GCD of " << a << " and " << b << " : " << gcd(a,b) << std::endl;
}
