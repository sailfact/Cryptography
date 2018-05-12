#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

long calcExp(long a, long b, long n)
{
    long ret = 1;

    a = a % n;

    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % n;

        b = b >> 1;
        a = (a * a) % n;
    }

    return ret;
}

// works for primes bigger than 2
bool isPrime(int p, int t)
{
    srand((unsigned)time(NULL));
    int a = 0;
    int e = 0;
    int r;
    bool ret;

    for (int i = 0; i < t; i ++)
    {
        a = (rand()%p-1)+1;
        e = (p-1)/2;
        r = calcExp(a,e,p);
        cout << a << "^" << e << " mod " << p << " = " << r << endl;
        if (r % p != 1 && r % p != p - 1)
            return false;
        else
            ret = true;
    }

    return ret;
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
