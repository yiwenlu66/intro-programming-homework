#include <stdio.h>

int main() {
    double y;
    y = 1.0 + 1.0 / (1.0 + 1.0 / (1.0 + 1.0 / 5.0));
    printf("%f\n", y);
    return 0;
}