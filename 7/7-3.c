/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-18
Description: Definite integrals.
*/

#include <stdio.h>
#include <math.h>
#define INFTY 0x7FFFFFFF
#define MAXN 1000
#define X0_1 0.0
#define XF_1 5.0
#define X0_2 2.0
#define XF_2 5.0
#define EPSILON 1E-6
#define abs(x) ((x) >= 0 ? (x): -(x))


double f1(double x)
{
    return pow(M_E, -pow(x, 2));
}

double f2(double x)
{
    return 1 - sin(x) * pow(M_E, -2 * x);
}

double riemann_sum(double (*fp)(double), double x_0, double x_f, int N)
{
    double dx, f_sum;
    int i;
    dx = (x_f - x_0) / N;
    f_sum = 0;
    for (i = 0; i < N; ++i)
        f_sum += (*fp)(x_0 + 1.0 * i / N * (x_f - x_0));
    return dx * f_sum;
}

double integral(double (*fp)(double), double x_0, double x_f, int* np)
{
    // Compute Riemann sum with 10n sections until the error is small enough,
    // returning the integral value and storing the required n.
    double curr, prev;
    double error = INFTY;
    curr = riemann_sum(fp, x_0, x_f, 10);
    for (*np = 2; error >= EPSILON; ++*np) {
        prev = curr;
        curr = riemann_sum(fp, x_0, x_f, 10 * (*np));
        error = abs((curr - prev) / curr);
    }
    return curr;
}

int main()
{
    int n;
    double i;
    i = integral(&f1, X0_1, XF_1, &n);
    printf("Integral of f(x)=e^(-x^2) on [%lf,%lf]: %lf, n=%d\n", X0_1, XF_1, i, n);
    i = integral(&f2, X0_1, XF_1, &n);
    printf("Integral of f(x)=1-sin(x)e^(-2x) on [%lf,%lf]: %lf, n=%d\n", X0_1, XF_1, i, n);
    i = integral(&f1, X0_2, XF_2, &n);
    printf("Integral of f(x)=e^(-x^2) on [%lf,%lf]: %lf, n=%d\n", X0_2, XF_2, i, n);
    i = integral(&f2, X0_2, XF_2, &n);
    printf("Integral of f(x)=1-sin(x)e^(-2x) on [%lf,%lf]: %lf, n=%d\n", X0_2, XF_2, i, n);
    return 0;
}

