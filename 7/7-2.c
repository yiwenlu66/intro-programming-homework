/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-17
Description: Swap the strings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 10000


void input(char* p1, char* p2)
{
    gets(p1);
    gets(p2);
}

void swap(char** pp1, char** pp2)
{
    char* t;
    t = *pp1;
    *pp1 = *pp2;
    *pp2 = t;
}

int main()
{
    char s1[20], s2[20];
    char* p1 = s1;
    char* p2 = s2;
    input(p1, p2);
    swap(&p1, &p2);
    printf("%s\n", p1);
    printf("%s\n", p2);
    return 0;
}

