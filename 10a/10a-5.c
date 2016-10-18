/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-20
Description: Closest pair.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

struct pair {
    int p1;
    int p2;
};

typedef struct pair pair;

pair closest(int *, int);
pair closest_rec(int, int *, int);

int main()
{
    int array[MAXN];
    int n;
    int i;
    pair result;
    printf("n:\n");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d", array + i);
    result = closest(array, n);
    printf("%d\n", abs(result.p1 - result.p2));
    printf("(%d, %d)\n", result.p1, result.p2);
    return 0;
}

pair closest(int* array, int n)
{
    return closest_rec(*array, array + 1, n - 1);
}

pair closest_rec(int point, int* array, int n)
{
    pair result;
    int i;
    if (n == 1) {
        result.p1 = point;
        result.p2 = *array;
        return result;
    }

    result = closest(array, n);
    for (i = 0; i < n; ++i)
        if (abs(point - *(array + i)) < abs(result.p1 - result.p2)) {
            result.p1 = point;
            result.p2 = *(array + i);
        }
    return result;
}
