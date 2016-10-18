#include <stdio.h>
#define MAXLEN 10

int main()
{
    int d;
    int b[MAXLEN];
    int i = 0;
    scanf("%d", &d);
    while (d > 0) {
        b[i++] = d % 2;
        d /= 2;
    }
    while (--i >= 0) {
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}
