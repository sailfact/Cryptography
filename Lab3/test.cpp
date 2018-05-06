#include <iostream>
#include <ctime>
#include <cstdlib>

int extendedGcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int tempX, tempY;
    int gcd = extendedGcd(b % a, a, &tempX, &tempY);

    *x = tempY - (b / a) * tempX;
    *y = tempX;

    return gcd;
}

long findE(long a)
{
    int x, y;
    srand((unsigned)time(NULL));

    int temp = (rand()%a-1)+1;
    while (extendedGcd(temp, a, &x, &y) != 1)
        --temp;

    return temp;
}

// long findD(int a,int b)
// {
//     int x, y;
//     extendedGcd(a,b,&x,&y);
//     std::cout << a << ' ' << b << ' ' << x << ' ' << y << std::endl;
//     if((a * x) + (b * y) == 1)
//         return x;
//     else 
//         throw "error getting d key";
// }
long findD(long int x, long int t)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

long calcExp(long a, long b, long n)
{
    long ret = 1;

    a = a % n;

    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % n;

        b = b>>1;
        a = (a * a) % n;
    }

    return ret;
}

long encrypt(long pt, long e, long n)
{
    long c;

    c = calcExp(pt, e, n);
    std::cout << pt<<"^"<<e<<" mod "<<n<<" = "<<c<<'\n';

    return c;
}

long decrypt(long ct, long d, long n)
{
    long m;

    m = calcExp(ct, d, n);
    std::cout << ct<<"^"<<d<<" mod "<<n<<" = "<<m<<'\n';

    return m;
}

int joinBlock(int a, int b)
{
    return (a * 1000) + b;
}

int main(void)
{
    std::string msg = "as";
    int p = 20011;
    int q = 50021;
    int pt = joinBlock(msg[0], msg[1]);
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = findE(phi);
    int d = findD(e, phi);
    int ct = encrypt(pt, e, n);
    pt = decrypt(ct, d, n);

}