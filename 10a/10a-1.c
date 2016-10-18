/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-15
Description: Address book.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 200
#define MAXENTRY 100

struct student {
    char name[MAXLEN];
    char number[MAXLEN];
    char native[MAXLEN];
    char id[MAXLEN];
    int age;
    char addr[MAXLEN];
    int gender; // 0 for male, 1 for female
    char tel[MAXLEN];
};

typedef struct student student;

student input();
int search(student *, int, char *);
void print(student);
void out(student *, int);

int main()
{
    student data[MAXENTRY];
    char query[MAXLEN];
    int nentry = 0;
    char option;
    int idx;
    while (!0) {
        printf("1) input\n2) search\n3) print all\n4) quit\n");
        while ((option = getchar()) == '\n');
        switch (option) {
        case '1':
            if (nentry < MAXENTRY)
                data[nentry++] = input();
            break;
        case '2':
            scanf("%s", query);
            idx = search(data, nentry, query);
            if (idx == -1)
                printf("not found\n");
            else
                print(data[idx]);
            break;
        case '3':
            out(data, nentry);
            break;
        case '4':
            return 0;
        default:
            printf("invalid input\n");
        }
    }
    return 0;
}

student input()
{
    student s;
    printf("name:\n");
    scanf("%s", s.name);
    printf("number:\n");
    scanf("%s", s.number);
    printf("native:\n");
    scanf("%s", s.native);
    printf("id:\n");
    scanf("%s", s.id);
    printf("age:\n");
    scanf("%d", &s.age);
    printf("address:\n");
    scanf("%s", s.addr);
    printf("gender (0 for male, 1 for female):\n");
    scanf("%d", &s.gender);
    printf("tel:\n");
    scanf("%s", s.tel);
    return s;
}

int search(student* data, int nentry, char* query)
{
    int i;
    for (i = 0; i < nentry; ++i)
        if (!strcmp(query, data[i].name) || !strcmp(query, data[i].number))
            return i;
    return -1;
}

void print(student entry)
{
    printf("%s\t", entry.name);
    printf("%s\t", entry.number);
    printf("%s\t", entry.native);
    printf("%s\t", entry.id);
    printf("%d\t", entry.age);
    printf("%s\t", entry.addr);
    printf("%c\t", entry.gender ? 'F' : 'M');
    printf("%s\n", entry.tel);
}

void out(student* data, int nentry)
{
    int i;
    for (i = 0; i < nentry; ++i)
        print(data[i]);
}
