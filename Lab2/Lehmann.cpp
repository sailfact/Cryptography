#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool isPrime(int p, int t)
{
    srand((unsigned)time(NULL));
    int a = 0;
    int r;
    bool isPrime = true;

    for (int i = 0; i < t; i ++)
    {
        a = (rand()%p-1)+1;
        r = (a^((p-1)/2))%p;
        if (r != 1 || r != -1)
        {
            return false;
        }
    }

    return isPrime;
}

int main(int argc, char **argv)
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

    return 0;
}