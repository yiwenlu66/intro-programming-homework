#include <stdio.h>

int main() {
    double x;
    printf("Please input x:\n");
    scanf("%lf", &x);
    if (x < 0)
        printf("(x)=-1\n");
    else if (x > 0)
        printf("(x)=+1\n");
    else
        printf("(x)=0\n");
    return 0;
}