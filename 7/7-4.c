/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-18
Description: Find root by secant method.
*/

#include <stdio.h>
#define f(x) ((x) * (x) * (x) - 5 * (x) * (x) + 16 * (x) - 80)
#define MAXTRY 100000
#define abs(x) ((x) >= 0 ? (x): -(x))


int main()
{
    double x, x2, epsilon;
    int ntry = 0;
    printf("Input epsilon, x1, x2:\n");
    scanf("%lf%lf%lf", &epsilon, &x, &x2);
    while (++ntry <= MAXTRY && abs(f(x)) > epsilon)
        x += (x2 - x) * (-f(x)) / (-f(x) + f(x2));
    if (abs(f(x)) <= epsilon)
        printf("x=%lf\n", x);
    else
        printf("Can't solve.\n");
    return 0;
}

