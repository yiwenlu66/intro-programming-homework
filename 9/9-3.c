/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-01
Description: Access array with pointers.
*/

#include <stdio.h>
#include <assert.h>
#define MAXN 10000

void input(int*, int*);
void add(int*, int);

int main()
{
    int n;
    int array[MAXN];
    int i;
    input(array, &n);
    add(array, n);
    for (i = 0; i < n; ++i)
        printf("%d ", *(array + i));
    printf("\n");
    return 0;
}

void input(int* array, int* np)
{
    int i;
    printf("Please input n:\n");
    scanf("%d", np);
    assert(*np < MAXN);
    printf("Please input %d integers:\n", *np);
    for (i = 0; i < *np; ++i)
        scanf("%d", array + i);
}

void add(int* array, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        *(array + i) = (*(array + i) % 2) ? (*(array + i) + 1) : (*(array + i) - 1);
}

