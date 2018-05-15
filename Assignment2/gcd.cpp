#include <iostream>
#include <cstdlib>
/// gcd
/// calculate the the greatest common divisor
/// recursively
int gcd(int a, int b)
{
    std::cout << "a = " << a << ", b = " << b << '\n'; 
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    if (argc == 3)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        std::cout << "GCD of " << a << " and " << b << " : " << gcd(a,b) << std::endl;
    }
    else 
        std::cout << "Not enough arguments" << '\n';
}
