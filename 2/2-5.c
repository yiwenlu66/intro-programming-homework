#include <stdio.h>

int main() {
    char c;
    printf("Please input a character:\n");
    scanf("%c", &c);
    if ('A' <= c && c <= 'Z')
        c += ('a' - 'A');
    printf("%c\n", c);
    return 0;
}