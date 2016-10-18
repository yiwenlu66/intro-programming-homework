/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-27
Description: Tell whether a year is leap.
*/

#include <stdio.h>

int isleap(int y)
{
    return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
}

int main()
{
    int y;
    scanf("%d", &y);
    if (isleap(y))
        printf("%d is leap year.\n", y);
    else
        printf("%d is not leap year.\n", y);
    return 0;
}
