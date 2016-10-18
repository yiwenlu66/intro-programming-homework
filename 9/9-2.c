/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-01
Description: Swap pointers.
*/

#include <stdio.h>

void input(int*, int*);
void SwapPoint(int**, int**);

int main()
{
    int i_a, i_b;
    int *ip1, *ip2;
    ip1 = &i_a;
    ip2 = &i_b;
    input(ip1, ip2);
    printf("初始\n");
	printf("i_a的地址=%#x, i_b的地址=%#x\n",&i_a,&i_b);
	printf("ip1的值=%#x, ip2的值=%#x\n",ip1,ip2);
	printf("ip1指向变量的值=%d, ip2指向变量的值 =%d\n",*ip1,*ip2);
    SwapPoint(&ip1, &ip2);
    printf("交换\n");
	printf("i_a的地址=%#x, i_b的地址=%#x\n",&i_a,&i_b);
	printf("ip1的值=%#x, ip2的值=%#x\n",ip1,ip2);
	printf("ip1指向变量的值=%d, ip2指向变量的值 =%d\n",*ip1,*ip2);
    return 0;
}

void input(int* p1, int* p2)
{
    scanf("%d%d", p1, p2);
}

void SwapPoint(int** pp1, int** pp2)
{
    int* tp;
    tp = *pp1;
    *pp1 = *pp2;
    *pp2 = tp;
}

