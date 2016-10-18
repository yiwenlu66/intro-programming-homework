/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-18
Description: Find longest string.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 100000


void input(char* s1, char* s2, char* s3)
{
    gets(s1);
    gets(s2);
    gets(s3);
}

void select(char* s1, char* s2, char* s3, char** max)
{
    *max = s1;
    if (strlen(s2) > strlen(*max))
        *max = s2;
    if (strlen(s3) > strlen(*max))
        *max = s3;
}

int main()
{
    char s1[MAXLEN], s2[MAXLEN], s3[MAXLEN];
    char* max;
    input(s1, s2, s3);
    select(s1, s2, s3, &max);
    printf("%s\n", max);
    return 0;
}

