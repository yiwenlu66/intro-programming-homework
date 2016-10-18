/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-01
Description: Average and max in 2-D array.
*/

#include <stdio.h>
#define INFTY 0x7fffffff
#define M 3
#define N 5

void intput(double [M][N]);
double average_row(double [N]);
double averag_All(double [M][N]);
double max(double [M][N]);
void list(double [M], double, double);

int main()
{
    double a[M][N];
    double row_avg[M];
    double all_avg, all_max;
    int i;
    intput(a);
    for (i = 0; i < M; ++i)
        row_avg[i] = average_row(a[i]);
    all_avg = averag_All(a);
    all_max = max(a);
    list(row_avg, all_avg, all_max);
    return 0;
}

void intput(double a[M][N])
{
    int i, j;
    for (i = 0; i < M; ++i) {
        printf("Please input a row of size %d:\n", N);
        for (j = 0; j < N; ++j)
            scanf("%lf", &a[i][j]);
    }
}

double average_row(double row[N])
{
    int i;
    double sum = 0;
    for (i = 0; i < N; ++i)
        sum += row[i];
    return sum / N;
}

double averag_All(double a[M][N])
{
    int i, j;
    double sum = 0;
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j)
            sum += a[i][j];
    return sum / M / N;
}

double max(double a[M][N])
{
    int i, j;
    double m = -INFTY;
    for (i = 0; i < M; ++i)
        for (j = 0; j < N; ++j)
            if (a[i][j] > m)
                m = a[i][j];
    return m;
}

void list(double row_avg[M], double all_avg, double all_max)
{
    int i;
    printf("The row averages are:\n");
    for (i = 0; i < M; ++i)
        printf("%lf\n", row_avg[i]);
    printf("The overall average is: %lf\n", all_avg);
    printf("The overall maximum is: %lf\n", all_max);
}

