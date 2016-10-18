/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-17
Description: Swap the integers.
*/

#include <stdio.h>


void Input(int* a, int* b)
{
    scanf("%d%d", a, b);
}

void swap(int* a, int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a, b;
    Input(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}

