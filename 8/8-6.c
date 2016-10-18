/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-29
Description: Interlace two strings.
*/

#include <stdio.h>
#define MAXLEN 30

void input(char*, char*);
char* interlaced(char*, char*);

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    char* result;
    char flag = '\0';
    while (flag != '@') {
        input(s1, s2);
        result = interlaced(s1, s2);
        printf("交错排列的字符串: %s\n", result);
        printf("按任意键继续，退出请按'@':\n");
        while (getchar() != '\n');
        flag = getchar();
    }
    return 0;
}

void input(char* p1, char* p2)
{
    printf("请输入字符串a:\n");
    scanf("%s", p1);
    printf("请输入字符串b:\n");
    scanf("%s", p2);
}

char* interlaced(char* p1, char* p2)
{
    static char result[MAXLEN];
    int i, j;
    int cursor = 0;
    for (i = j = 0; *(p1 + i) || *(p2 + j);) {
        if (*(p1 + i))
            result[cursor++] = *(p1 + (i++));
        if (*(p2 + j))
            result[cursor++] = *(p2 + (j++));
    }
    return result;
}

