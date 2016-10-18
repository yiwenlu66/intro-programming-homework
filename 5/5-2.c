/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-27
Description: Reverse a string.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 100

int main()
{
    char str1[MAXLEN], str2[MAXLEN];
    int len, i;
    gets(str1);
    len = strlen(str1);
    for (i = 0; i < len; ++i)
        str2[i] = str1[len - 1 - i];
    str2[i] = '\0';
    printf("%s\n", str2);
    return 0;
}
