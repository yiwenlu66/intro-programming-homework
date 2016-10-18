/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-04
Description: Generate some random integers between 0 and 99.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NLOOP 100
#define MAX 99.999999


int myrand()
{
    return (int) rand() * MAX / RAND_MAX;
}

int main()
{
    int i;
    srand(time(0));
    for (i = 0; i < NLOOP; ++i)
        printf("%d\n", myrand());
    return 0;
}
