/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-30
Description: Find largest element in array.
*/

#include <stdio.h>
#include <assert.h>
#define MAXN 10000
#define INFTY 0x7FFFFFFF

void Input(int*, int);
int* findmax(int*, int);

int main()
{
    int n;
    int array[MAXN];
    int* pmax;
    printf("Please input n:\n");
    scanf("%d", &n);
    assert(n < MAXN);
    Input(array, n);
    pmax = findmax(array, n);
    printf("%d\n", *pmax);
    return 0;
}

void Input(int* array, int n)
{
    int i;
    printf("Please input %d integer(s):\n", n);
    for (i = 0; i < n; ++i)
        scanf("%d", &array[i]);
}

int* findmax(int* array, int n)
{
    int i;
    int max_idx;
    int max = -INFTY;
    for (i = 0; i < n; ++i)
        if (array[i] > max) {
            max = array[i];
            max_idx = i;
        }
    return array + max_idx;
}

