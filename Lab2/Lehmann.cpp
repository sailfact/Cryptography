#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// works for primes bigger than 2
bool isPrime(int p, int t)
{
    srand((unsigned)time(NULL));
    int a = 0;
    int e = 0;
    int r;

    for (int i = 0; i < t; i ++)
    {
        a = (rand()%p-1)+1;
        e = (p-1)/2;
        r = ((int)pow(a,e)) % p;
        if (r % p == p - 1)
        {
             return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int p = atoi(argv[1]);
        int t = atoi(argv[2]);

        if (isPrime(p, t))
        {
            cout << "prime\n";
        }
        else
        {
            cout << "not prime\n";
        }
    }

    return 0;
}
