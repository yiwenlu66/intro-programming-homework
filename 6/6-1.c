/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-04
Description: Implement the functions of strlen, strcpy and strcmp.
*/

#include <stdio.h>
#define MAXLEN 10000


int mystrlen(char* str)
{
    int n = 0;
    while (str[n] != '\0')
        ++n;
    return n;
}

void mystrcpy(char* destin, char* source)
{
    int i = 0;
    do {
        destin[i] = source[i];
        ++i;
    } while (source[i] != '\0');
    destin[i] = '\0';
}

int mystrcmp(char* str1, char* str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
        ++i;
    }
    if (str1[i] != '\0')
        return 1;
    if (str2[i] != '\0')
        return -1;
    return 0;
}

int main()
{
    char str1[MAXLEN], str2[MAXLEN];
    while (!0) {
        printf("1) strlen  2) strcpy  3) strcmp 4) exit\n");
        switch (getchar()) {
        case '1':
            while (getchar() != '\n');
            gets(str1);
            printf("%d\n", mystrlen(str1));
            break;
        case '2':
            while (getchar() != '\n');
            gets(str1);
            mystrcpy(str2, str1);
            printf("%s\n", str2);
            break;
        case '3':
            while (getchar() != '\n');
            gets(str1);
            gets(str2);
            switch (mystrcmp(str1, str2)) {
            case 1:
                printf("str1 is larger\n");
                break;
            case -1:
                printf("str2 is larger\n");
                break;
            case 0:
                printf("equal\n");
            }
            break;
        case '4':
            return 0;
        default:
            printf("invalid input\n");
        }
    }
    return 0;
}
