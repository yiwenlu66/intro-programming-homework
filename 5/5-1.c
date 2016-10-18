/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-27
Description: Find the min, max and average of n numbers,
             and count how the percentage of them below average.
*/


#include <stdio.h>
#include <assert.h>
#define MAXN 100
#define INF 0x7FFFFFFF

int main()
{
    int data[MAXN];
    int min = INF, max = -INF;
    int n, sum, i, nbelow;
    double avg;
    double pbelow;  // proportion below average
    scanf("%d", &n);
    assert(n < MAXN);
    sum = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
        sum += data[i];
        if (data[i] > max)
            max = data[i];
        if (data[i] < min)
            min = data[i];
    }
    avg = sum * 1.0 / n;
    nbelow = 0;
    for (i = 0; i < n; ++i)
        if (data[i] < avg)
            ++nbelow;
    pbelow = nbelow * 1.0 / n;
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Average: %lf\n", avg);
    printf("Percentage below average: %.2lf%%\n", 100 * pbelow);
    return 0;
}
