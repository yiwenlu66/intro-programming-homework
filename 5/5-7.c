/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-27
Description: Caesar cipher.
*/

#include <stdio.h>
#include <string.h>
#define SHIFT 4
#define MAXLEN 10000

char shiftchar(char c, int shift)
{
    if ('a' <= c && c <= 'z')
        return 'a' + (c - 'a' + ('z' - 'a' + 1) + shift) % ('z' - 'a' + 1);
    if ('A' <= c && c <= 'Z')
        return 'A' + (c - 'A' + ('Z' - 'A' + 1) + shift) % ('Z' - 'A' + 1);
    return c;
}

int main()
{
    char s[MAXLEN];
    char method;    // '1' for encrypt, '2' for decrypt
    int shift = 0;
    int i;
    printf("Please input a string:\n");
    gets(s);
    printf("1) encrypt\n2) decrypt\n");
    scanf("%c", &method);
    switch (method) {
    case '1':
        shift = SHIFT;
        break;
    case '2':
        shift = -SHIFT;
        break;
    default:
        printf("invalid input\n");
    }
    if (shift) {
        for (i = 0; i < strlen(s); ++i)
            s[i] = shiftchar(s[i], shift);
        printf("%s\n", s);
    }
    return 0;
}
