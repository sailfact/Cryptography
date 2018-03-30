#include <iostream>

int findInverse(int a, int n)
{
    int b = 0;
    for (int i = 0; i < n; i ++)
    {
        if (((a*i)%n) == 1)
        {
            b = i;
        }
    }

    return b;
}

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    int n = atoi(argv[2]);
    int b = findInverse(a, n);

    std::cout << a << b << "mod" << n <<"=1\n";

    return 0;
}