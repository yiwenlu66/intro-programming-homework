/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-24
Description: Find a1<=a2<=a3<=20, a1<a4<=a5<=a6<=20, s.t. a1^2+a2^2+a3^2=a4^2+a5^2+a6^2.
*/

#include <stdio.h>
#define UPPER 20
#define MAXLEN UPPER * UPPER * UPPER
#define INFTY 0x7fffffff


void sort(int*, int*, int);


int main()
{
    int sum[MAXLEN];
    int array1[MAXLEN], array2[MAXLEN], array3[MAXLEN];
    int order[MAXLEN]; // order[0] is the index of the smallest sum, etc.
    int x1, x2, x3;
    int len = 0;
    int start, end;
    int i, j;

    for (x1 = 1; x1 <= UPPER; ++x1)
        for (x2 = x1; x2 <= UPPER; ++x2)
            for(x3 = x2; x3 <= UPPER; ++x3) {
                array1[len] = x1;
                array2[len] = x2;
                array3[len] = x3;
                sum[len++] = x1 * x1 + x2 * x2 + x3 * x3;
            }

    for (i = 0; i < len; ++i) {
        order[i] = i;
    }
    sort(sum, order, len);

    for (start = 0; start < len; start = end) {
        for (end = start; end <= len && sum[start] == sum[end]; ++end);
        if (end - start > 1) {
            for (i = start; i < end - 1; ++i)
                for (j = i + 1; j < end; ++j)
                    if (array1[order[i]] < array1[order[j]])
                        printf("a1=%d, a2=%d, a3=%d, a4=%d, a5=%d, a6=%d\n",
                               array1[order[i]], array2[order[i]], array3[order[i]],
                               array1[order[j]], array2[order[j]], array3[order[j]]
                              );
        }
    }
    return 0;
}


void sort(int* sum, int* order, int len)
{
    int i, j;
    int t;
    for (i = 0; i < len; ++i)
        for (j = len - 1; j > i; --j)
            if (sum[j] < sum[j - 1]) {
                t = sum[j];
                sum[j] = sum[j - 1];
                sum[j - 1] = t;
                t = order[j];
                order[j] = order[j - 1];
                order[j - 1] = t;
            }
}

