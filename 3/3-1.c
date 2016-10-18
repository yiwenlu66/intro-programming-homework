#include <stdio.h>
#include <string.h>
#define MAXLEN 40

int main() {
    char s[MAXLEN];
    printf("Please input a string (less than 40 characters):\n");
    scanf("%s", s);
    printf("The string is: %s\n", s);
    printf("The length of the string is: %d\n", strlen(s));
    return 0;
}