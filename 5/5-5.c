/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-27
Description: Solve Ax + By = C (x, y are positive integers).
*/

#include <stdio.h>
#define A 3
#define B 7
#define C 901

int main()
{
    int x;
    for (x = 0; x <= C / A; ++x)
        if (!((C - A * x) % B))
            printf("x = %3d, y = %3d\n", x, (C - A * x) / B);
    return 0;
}
