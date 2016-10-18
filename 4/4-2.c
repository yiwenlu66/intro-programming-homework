/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-19
Description: repayment per installment = (principal / number of installments)
                                       + (principal - repaid principal) * interest rate
*/

#include <stdio.h>
#define RATE 0.005

int main()
{
    int ni, i; //number of installments, current installment
    double p, rppi;  // principal, repaid principal per installment
    scanf("%lf%d", &p, &ni);
    rppi = p / ni;
    for (i = 0; i < ni; ++i)
        printf("%lf\n", rppi + (p - i * rppi) * RATE);
    return 0;
}
