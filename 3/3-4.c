#include <stdio.h>

int main() {
    float price, weight, s, discount, freight;
    printf("Please input price, weight and distance:\n");
    scanf("%f%f%f", &price, &weight, &s);
    if (s < 250)
        discount = 0;
    else if (s < 500)
        discount = 0.02;
    else if (s < 1000)
        discount = 0.05;
    else if (s < 2000)
        discount = 0.08;
    else if (s < 3000)
        discount = 0.1;
    else
        discount = 0.15;
    freight = price * weight * s * (1 - discount);
    printf("The freight is: %f\n", freight);
}