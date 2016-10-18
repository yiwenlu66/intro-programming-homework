/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-19
Description: Find m (1 <= m <= n <= 1000), s.t. m, m ^ 2, m ^ 3 are all palindromes.
*/

#include <stdio.h>
#define MAXLEN 10

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

void unittest()
{
    const int testcase[8] = {1, 10, 11, 121, 1221, 1234, 12321, 1234554321};
    int i;
    for (i = 0; i < 8; ++i)
        printf("%d\n", ispal(testcase[i]));
}

int main()
{
    // unittest();
    int m, n;
    scanf("%d", &n);
    for (m = 1; m <= n; ++m)
        if (ispal(m) && ispal(m * m) && ispal(m * m * m))
            printf("%d\n", m);
    return 0;
}
