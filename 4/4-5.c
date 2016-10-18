/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-19
Description: Taylor expand e ^ x so that error < 1e-4.
*/

#include <stdio.h>
#include <math.h>
#define MAXERR 1E-4
#define PRECISION 4
#define TESTSIZE 3
#define INF 0x7FFFFFFF

int factorial(int x)
{
    int f, i;
    f = 1;
    for (i = 1; i <= x; ++i)
        f *= i;
    return f;
}

void taylor(double x, double* sum, int* N)
{
    /*
    Taylor expand e ^ x so that error < 1e-4,
    storing the result and the power needed in sum and N, respectively.
    */
    double err = INF;
    *sum = *N = 0;
    while (err >= MAXERR) {
        *sum += pow(x, *N) / factorial(*N);
        err = pow(x, *N + 1) / factorial(++*N);
    }
}

int main()
{
    const x[TESTSIZE] = {1, 2, 3};
    double sum;
    int N, i;
    for (i = 0; i < TESTSIZE; ++i) {
        taylor(x[i], &sum, &N);
        printf("%.*lf\t%d\n", PRECISION, sum, N);
    }
    return 0;
}
