/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-20
Description: Implement strlen recursively.
*/

#include <stdio.h>
#define MAXLEN 1000

int mystrlen(char *);

int main()
{
    char s[MAXLEN];
    gets(s);
    printf("%d", mystrlen(s));
    return 0;
}

int mystrlen(char* s)
{
    if (*s == '\0')
        return 0;
    return 1 + mystrlen(s + 1);
}
