/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-19
Description: Print the i-th (0 < i <= 10) Pascal matrix.
*/

#include <stdio.h>
#define MAXI 10

int main()
{
    int pas[MAXI][MAXI] = {0};
    int i, j, k;
    scanf("%d", &i);

    // generate the matrix
    pas[0][0] = 1;
    for (j = 1; j < i; ++j) {
        pas[j][0] = 1;
        for (k = 1; k <= j; ++k)
            pas[j][k] = pas[j - 1][k - 1] + pas[j - 1][k];
    }

    // print the matrix
    for (j = 0; j < i; ++j) {
        for (k = 0; k <= j; ++k)
            printf("%5d", pas[j][k]);
        printf("\n");
    }
    return 0;
}
