/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-18
Description: Correct program.
*/

/*
原程序中的错误：
1. function(int*)未在使用前声明.
2. printf后缺左括号.
3. printf的第一个参数用了全角双引号，应为半角双引号.
4. a是function()中的局部变量，改变a所指向的地址不会改变主函数中c的值，因此c未初始化.

以下是改正后的程序：
*/

#include<stdio.h>

void function(int*);

int main()
{
    int c;
    function(&c);
    printf("c 的值是:%d\n",c);
    return(0);
}
//-----------------------
void function(int *a)
{
    int b=5;
    *a=b;
}

