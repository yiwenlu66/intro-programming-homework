/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-12-20
Description: Address book with function pointers.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 200
#define MAXENTRY 100
#define NFUNC 3

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

int func_in(student *, int);
int func_search(student *, int);
int func_out(student *, int);

student input();
int search(student *, int, char *);
void print(student);
void out(student *, int);

int main()
{
    int (*func[NFUNC])(student *, int) = {func_in, func_search, func_out};
    student data[MAXENTRY];
    int nentry = 0;
    char option;
    while (!0) {
        printf("1) input\n2) search\n3) print all\n4) quit\n");
        while ((option = getchar()) == '\n');
        if (0 <= option - '1' && option - '1' < NFUNC)
            nentry = (func[option - '1'])(data, nentry);
        else if (option - '1' == NFUNC)
            return 0;
        else
            printf("invalid input\n");
    }
    return 0;
}

int func_in(student* data, int nentry)
{
    if (nentry < MAXENTRY)
        data[nentry++] = input();
    return nentry;
}

int func_search(student* data, int nentry)
{
    char query[MAXLEN];
    int idx;
    scanf("%s", query);
    idx = search(data, nentry, query);
    if (idx == -1)
        printf("not found\n");
    else
        print(data[idx]);
    return nentry;
}

int func_out(student* data, int nentry)
{
    out(data, nentry);
    return nentry;
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
