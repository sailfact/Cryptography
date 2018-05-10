#include <iostream>
#include <ctime>
#include <cstdlib>

typedef unsigned long long int u64;

u64 extendedGcd(u64 a, u64 b, u64 *x, u64 *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    u64 tempX, tempY;
    u64 gcd = extendedGcd(b % a, a, &tempX, &tempY);

    *x = tempY - (b / a) * tempX;
    *y = tempX;

    return gcd;
}

u64 findE(long a)
{
    u64 x, y;
    srand((unsigned)time(NULL));

    u64 temp = (rand()%a-1)+1;
    while (extendedGcd(temp, a, &x, &y) != 1)
        --temp;

    return temp;
}

// long findD(long a,long b)
// {
//     long x, y;
//     extendedGcd(a,b,&x,&y);
//     std::cout << a << ' ' << b << ' ' << x << ' ' << y << std::endl;
//     if((a * x) + (b * y) == 1)
//         return x;
//     else 
//         throw "error getting d key";
// }
u64 findD(u64 x, u64 t)
{
    u64 k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

u64 calcExp(long a, long b, long n)
{
    u64 ret = 1;

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

u64 encrypt(long pt, u64 e, u64 n)
{
    u64 c;

    c = calcExp(pt, e, n);
    std::cout << pt<<"^"<<e<<" mod "<<n<<" = "<<c<<'\n';

    return c;
}

u64 decrypt(long ct, u64 d, u64 n)
{
    u64 m;

    m = calcExp(ct, d, n);
    std::cout << ct<<"^"<<d<<" mod "<<n<<" = "<<m<<'\n';

    return m;
}

long joinBlock(long a, long b)
{
    return (a * 1000) + b;
}

int main(void)
{
    std::string msg = "  ";
    std::string msg2 = "a)";
    u64 p = 30011;
    u64 q = 70001;
    u64 pt = joinBlock(msg[0], msg[1]);
    u64 pt2 = joinBlock(msg2[0], msg2[1]);
    u64 n = p * q;
    u64 phi = (p - 1) * (q - 1);
    u64 e = findE(phi);
    u64 d = findD(e, phi);
    u64 ct = encrypt(pt, e, n);
    u64 ct2 = encrypt(pt2, e, n);
    pt = decrypt(ct, d, n);
    pt2 = decrypt(ct2, d, n);

}