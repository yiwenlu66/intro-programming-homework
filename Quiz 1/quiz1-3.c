#include <stdio.h>
#include <string.h>
#define MAXLEN 50

int main()
{
    int n;
    char s[MAXLEN];
    gets(s);
    scanf("%d", &n);
    for (; n < strlen(s); ++n)
        s[n] = s[n + 1];
    printf("%s\n", s);
    return 0;
}
