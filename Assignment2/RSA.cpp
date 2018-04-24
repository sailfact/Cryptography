#include "RSA.h"

int extendedGcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int tempX, tempY;
    int gcd = extendedGcd(b%a, &tempX, &tempY);

    *x = tempY - (b/a) * tempX;
    *y = tempX;

    return gcd;
}
