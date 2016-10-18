#include <stdio.h>
#include <math.h>

int main() {
    double a, b, y;
    printf("Please input a and b:\n");
    scanf("%lf%lf", &a, &b);
    y = sqrt(a * a + b * b);
    printf("y = %lf\n", y);
    return 0;
}