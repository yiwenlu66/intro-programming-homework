/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-20
Description: Recursive search.
*/

#include <stdio.h>
#define MAXN 100

int search(int *, int, int, int);
int input(int *);

int main()
{
    int array[MAXN];
    int N;
    int key;
    int result;
    N = input(array);
    printf("search key:\n");
    scanf("%d", &key);
    result = search(array, key, 0, N);
    if (result == -1)
        printf("not found\n");
    else
        printf("%d", result);
    return 0;
}

int input(int* array)
{
    int N;
    int i;
    printf("N:\n");
    scanf("%d", &N);
    for (i = 0; i < N; ++i)
        scanf("%d", array + i);
    return N;
}

int search(int* array, int key, int start, int end)
{

    if (array[start] == key)
        return start;
    if (end - start == 1)
        return -1;
    return search(array, key, start + 1, end);
}
