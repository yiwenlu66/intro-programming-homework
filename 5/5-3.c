/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-27
Description: Append input to a string until overflow.
*/

#include <stdio.h>
#include <string.h>
#define SIZE 40

int main()
{
    char str1[SIZE], str2[SIZE];
    int i, len1, len2;
    str1[0] = '\0';
    len1 = 0;
    while (!0) {
        gets(str2);
        len2 = strlen(str2);
        if (len1 + len2 < SIZE) {
            for (i = 0; i < len2; ++i)
                str1[len1 + i] = str2[i];
            str1[len1 + i] = '\0';
            len1 += len2;
            printf("%s\n", str1);
        } else {
            printf("Overflow.\n");
            break;
        }
    }
    return 0;
}
