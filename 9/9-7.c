/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-01
Description: Lexicographical order.
*/

#include <stdio.h>
#include <string.h>
#define NWORD 5
#define MAXLEN 20

void input(char [NWORD][MAXLEN]);
void bubbleSort(char**);
void output(char**);

int main()
{
    char word[NWORD][MAXLEN];
    char* p[NWORD];
    int i;
    for (i = 0; i < NWORD; ++i)
        p[i] = word[i];
    input(word);
    bubbleSort(p);
    output(p);
    return 0;
}

void input(char dest[NWORD][MAXLEN])
{
    int i;
    for (i = 0; i < NWORD; ++i)
        scanf("%s", dest[i]);
    printf("\n");
}

void bubbleSort(char** ap)
{
    // sort an array of pointers
    int i, j;
    char* t;
    for (i = 0; i < NWORD; ++i)
        for (j = NWORD - 1; j > i; --j)
            if (strcmp(ap[j], ap[j - 1]) < 0) {
                t = ap[j];
                ap[j] = ap[j - 1];
                ap[j - 1] = t;
            }
}

void output(char** ap)
{
    int i;
    for (i = 0; i < NWORD; ++i)
        printf("%s\n", ap[i]);
}

