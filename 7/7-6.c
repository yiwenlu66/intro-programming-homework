/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-18
Description: Find longest array.
*/

#include <stdio.h>
#define MAXLEN 100000


void input(int* c1, int* c2, int* c3, int* n1, int* n2, int* n3)
{
    int i;
    printf("n1:\n");
    scanf("%d", n1);
    printf("Enter %d integers:\n", *n1);
    for (i = 0; i < *n1; ++i)
        scanf("%d", c1 + i);

    printf("n2:\n");
    scanf("%d", n2);
    printf("Enter %d integers:\n", *n2);
    for (i = 0; i < *n2; ++i)
        scanf("%d", c2 + i);

    printf("n3:\n");
    scanf("%d", n3);
    printf("Enter %d integers:\n", *n3);
    for (i = 0; i < *n3; ++i)
        scanf("%d", c3 + i);
}

void select(int* c1, int* c2, int* c3, int n1, int n2, int n3, int** max, int* nmax)
{
    *max = c1;
    *nmax = n1;

    if (n2 > *nmax) {
        *max = c2;
        *nmax = n2;
    }

    if (n3 > *nmax) {
        *max = c3;
        *nmax = n3;
    }
}

int main()
{
    int c1[MAXLEN], c2[MAXLEN], c3[MAXLEN];
    int n1, n2, n3, nmax;
    int i;
    int* max;
    input(c1, c2, c3, &n1, &n2, &n3);
    select(c1, c2, c3, n1, n2, n3, &max, &nmax);
    for (i = 0; i < nmax; ++i)
        printf("%d ", *(max + i));
    printf("\n");
    return 0;
}

