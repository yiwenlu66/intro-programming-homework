/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-19
Description: Multiply large numbers.
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAXLEN 10000

void split(char* X, int* x, int len)
{
    // Read string X into integer array x, in which x[0] is the lowest digit.
    int i;
    for (i = 0; i < len; ++i)
        x[i] = X[len - 1 - i] - '0';
}

void merge(int* x, int maxlen, char* X)
{
    // Inverse of split.
    int len, i;
    len = MAXLEN;
    while (x[len - 1] == 0) {
        --len;
    }
    for (i = 0; i < len; ++i)
        X[len - 1 - i] = '0' + x[i];
    X[len] = '\0';
}

void add(int* x, int d, int i)
{
    // Add d (0 <= d <= 81) to x[i], dealing with carry.
    int carry;
    x[i] += d;
    if (x[i] >= 10) {
        carry = x[i] / 10;
        x[i] -= 10 * carry;
        add(x, carry, i + 1);
    }
}

int main()
{
    int a[MAXLEN], b[MAXLEN], c[MAXLEN] = {0};
    char A[MAXLEN], B[MAXLEN], C[MAXLEN];
    int m, n, i, j;
    scanf("%s%s", A, B);
    n = strlen(A);
    m = strlen(B);
    assert(n >= m);
    assert(m + n <= MAXLEN);
    split(A, a, n);
    split(B, b, m);
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            add(c, a[j] * b[i], i + j);
    merge(c, MAXLEN, C);
    printf("%s\n", C);
    return 0;
}
