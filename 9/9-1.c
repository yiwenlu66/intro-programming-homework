#include<stdio.h>
int *input(int *);
int *findmax(int *,int);
int main()
{  
	int *p,len;
	p=input(&len);
	printf("Max=%d\n",*(findmax(p,len)));
	return(0);
}
//输入整数序列，返回该数组
int *input(int *len)
{ 
	static int p[100];
	printf("输入序列长度：\n");  
	scanf("%d",len);
	for(int i=0;i<*len;i++){
		printf("输入序列：\n");
		scanf("%d",&p[i]);
	}
	return(p);
}
//在整数序列中找最大值元素，返回该元素地址
int *findmax(int *p,int len)
{
    int *max=p;
    for(int i=1;i<len;i++)if(*max<p[i])max=&p[i];
    return(max);
}
