/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-04
Description: Compute the first N items of the Fibonacci series.
*/

#include <stdio.h>
#define N 20


void fibo(int n, int* f)
{
    // store the first n items of the Fibonacci series into f
    int i;
    if (n >= 1)
        f[0] = 1;
    if (n >= 2)
        f[1] = 1;
    if (n >= 3)
        for (i = 2; i < n; ++i)
            f[i] = f[i - 1] + f[i - 2];
}

int main()
{
    int f[N];
    int i;
    fibo(N, f);
    for (i = 0; i < N; ++i)
        printf("%d\n", f[i]);
    return 0;
}
