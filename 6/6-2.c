/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-04
Description: Compute 2x! + 3y!.
*/

#include <stdio.h>


long long factorial(int x)
{
    long long f = 1;
    int i;
    for (i = 1; i <= x; ++i)
        f *= i;
    return f;
}

int main()
{
    int x, y;
    long long s;
    scanf("%d%d", &x, &y);
    s = 2 * factorial(x) + 3 * factorial(y);
    printf("%ld\n", s);
    return 0;
}
