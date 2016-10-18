/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-19
Description: Find the first 40 items of Fibonacci series.
*/

#include <stdio.h>
#define SIZE 40

int main()
{
    int f[SIZE];
    int n;
    f[0] = f[1] = 1;
    for (n = 2; n < SIZE; ++n)
        f[n] = f[n - 1] + f[n - 2];
    for (n = 0; n < SIZE; ++n)
        printf("%d\n", f[n]);
    return 0;
}
