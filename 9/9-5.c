/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-01
Description: Playing with 2D array.
*/

#include <stdio.h>
#define M 3
#define N 5

void output(int (*)[N], int);
void Double(int (*)[N], int);

int main()
{
    int a[M][N];
    int i, j;
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j)
            a[i][j] = 10 * (i + 1) + (j + 1);
    output(a, M);
    Double(a, M);
    output(a, M);
    return 0;
}

void output(int (*a)[N], int m)
{
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < N; ++j)
            printf("%6d", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void Double(int (*a)[N], int m)
{
    int i, j;
    for (i = 0; i < m; ++i)
        for (j = 0; j < N; ++j)
            a[i][j] = 2 * a[i][j];
}

