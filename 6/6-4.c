/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-04
Description: Find m (1 <= m <= n <= 1000), s.t. m, m ^ 2, m ^ 3 are all palindromes.
*/

#include <stdio.h>
#define MAXLEN 1000


int input()
{
    int n;
    scanf("%d", &n);
    return n;
}

int ispal(int m)
{
    int digits[MAXLEN];
    int t, i, ispal, len;
    i = 0;

    // divide m into digits
    while (m > 0) {
        t = m / 10;
        digits[i++] = m - 10 * t;
        m = t;
    }
    len = i;

    // check whether m is palindrome
    ispal = 1;
    for (i = 0; i <= (len + 1) / 2; ++i)
        if (digits[i] != digits[len - 1 - i]) {
            ispal = 0;
            break;
        }
    return ispal;
}

int* palindrome(int n)
{
    // find a list m[i] (1 <= m[i] <= n <= 1000),
    // s.t. m[i], m[i] ^ 2, m[i] ^ 3 are all palindromes
    static int m[MAXLEN] = {0};
    int i, x;
    i = 0;
    for (x = 1; x <= n; ++x)
        if (ispal(x) && ispal(x * x) && ispal(x * x * x))
            m[i++] = x;
    return m;
}

void output(int* m)
{
    int i = 0;
    while (m[i] != 0)
        printf("%d\n", m[i++]);
}

int main()
{
    int n;
    int* m;
    n = input();
    m = palindrome(n);
    output(m);
    return 0;
}
