/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-11-30
Description: Nslookup.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define NENTRY 6

typedef struct record record;

struct record {
    char hostname[MAXLEN];
    char ip[MAXLEN];
    char dept[MAXLEN];
    char username[MAXLEN];
};

int search_IP(const record*, char*);
int search_DomainName(const record*, char*);
void print_rec(record);

int main()
{
    const record data[NENTRY] = {
        {"Au-507",       "166.111.166.255", "自动化系", "张三"},
        {"Au-123",       "166.111.166.112", "自动化系", "李四"},
        {"Civil-101",    "166.111.123.233", "土木系",   "王武"},
        {"Civil-110",    "166.111.123.112", "土木系",   "赵六"},
        {"Chemical-230", "166.111.23.67",   "化工系",   "钱其"},
        {"Chemical-113", "166.111.23.78",   "化工系",   "化任"},
    };
    int (*const functions[2])(const record*, char*) = {&search_IP, &search_DomainName};
    char input[MAXLEN];
    int output;
    char run_flag = '\0';
    int input_flag;
    char option;
    while (run_flag != '@') {
        input_flag = 1;
        printf("1) 域名解析\n2) IP信息查询\n");
        while ((option = getchar()) == '\n');
        switch (option) {
            case '1':
                printf("请输入域名:\n");
                break;
            case '2':
                printf("请输入IP地址:\n");
                break;
            default:
                input_flag = 0;
                printf("输入错误\n");
        }
        if (input_flag) {
            scanf("%s", input);
            output = functions[option - '1'](data, input);
            if (output == -1)
                printf("找不到记录\n");
            else
                print_rec(data[output]);
        }
        printf("按任意键继续，退出请按'@':\n");
        while (getchar() != '\n');
        run_flag = getchar();
    }
    return 0;
}


int search_IP(const record* data, char* hostname)
{
    int i;
    for (i = 0; i < NENTRY; ++i)
        if (!strcmp(hostname, data[i].hostname))
            return i;
    return -1;
}

int search_DomainName(const record* data, char* ip)
{
    int i;
    for (i = 0; i < NENTRY; ++i)
        if (!strcmp(ip, data[i].ip))
            return i;
    return -1;
}

void print_rec(record rec)
{
    printf(
            "机器名: %s\tIP地址: %s\t单位: %s\t用户名: %s\n",
            rec.hostname,
            rec.ip,
            rec.dept,
            rec.username
          );
}

