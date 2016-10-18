/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-30
Description: Query namelist.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define NENTRY 10

typedef struct student student;

struct student {
    char id[MAXLEN];
    char dept[MAXLEN];
    int isforeign;
};

char* Search_Department(const student*, char*);
int Student_Total(const student*, char*);
int Student_Nationality(const student*, int);

int main()
{
    const student data[NENTRY] = {
        {"030156", "土木工程系", 0},
        {"030204", "土木工程系", 0},
        {"030184", "土木工程系", 0},
        {"030187", "土木工程系", 0},
        {"03W101", "自动化系",   1},
        {"03W102", "自动化系",   1},
        {"031569", "自动化系",   0},
        {"031602", "自动化系",   0},
        {"031603", "自动化系",   0},
        {"03W103", "自动化系",   1},
    };
    char input[MAXLEN];
    char* output_c;
    int output_i;
    char run_flag = '\0';
    char option;
    while (run_flag != '@') {
        printf("1) 系别查询\n2) 系别总人数\n3) 中国/留学生总人数\n");
        while ((option = getchar()) == '\n');
        switch (option) {
            case '1':
                printf("请输入学号:\n");
                scanf("%s", input);
                output_c = Search_Department(data, input);
                printf("%s\n", output_c);
                break;
            case '2':
                printf("请输入系别:\n");
                scanf("%s", input);
                output_i = Student_Total(data, input);
                printf("%d\n", output_i);
                break;
            case '3':
                printf("请输入\"中国\"或\"留学生\":\n");
                scanf("%s", input);
                if (!strcmp(input, "中国")) {
                    output_i = Student_Nationality(data, 0);
                    printf("%d\n", output_i);
                }
                else if (!strcmp(input, "留学生")) {
                    output_i = Student_Nationality(data, 1);
                    printf("%d\n", output_i);
                }
                else
                    printf("输入错误\n");
                break;
            default:
                printf("输入错误\n");
        }
        printf("按任意键继续，退出请按'@':\n");
        while (getchar() != '\n');
        run_flag = getchar();
    }
    return 0;
}


char* Search_Department(const student* data, char* id)
{
    int i;
    static char dept[MAXLEN];
    for (i = 0; i < NENTRY; ++i)
        if (!strcmp(id, data[i].id)) {
            strcpy(dept, data[i].dept);
            return dept;
        }
    strcpy(dept, "不存在");
    return dept;
}

int Student_Total(const student* data, char* dept)
{
    int i;
    int count = 0;
    for (i = 0; i < NENTRY; ++i)
        if (!strcmp(dept, data[i].dept))
            ++count;
    return count;
}

int Student_Nationality(const student* data, int isforeign)
{
    int i;
    int count = 0;
    for (i = 0; i < NENTRY; ++i)
        if (isforeign == data[i].isforeign)
            ++count;
    return count;
}

