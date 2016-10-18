#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define CAPACITY 10
#define NO_LEN 6

void init_no_list(char no_list[][NO_LEN + 1]) {
    strcpy(no_list[0], "030156");
    strcpy(no_list[1], "030204");
    strcpy(no_list[2], "030184");
    strcpy(no_list[3], "030187");
    strcpy(no_list[4], "03W101");
    strcpy(no_list[5], "03W102");
    strcpy(no_list[6], "031569");
    strcpy(no_list[7], "031602");
    strcpy(no_list[8], "031603");
    strcpy(no_list[9], "03W103");
}

int get_count(char no_list[][NO_LEN + 1], char prefix[]) {
    // get the count of numbers in no_list with the given prefix
    int count, i;
    count = 0;
    for (i = 0; i < CAPACITY; ++i)
        if (!strncmp(no_list[i], prefix, strlen(prefix)))
            ++count;
    return count;
}

int main() {
    char query[MAXLEN];
    char no_list[CAPACITY][NO_LEN + 1];
    int count;
    printf("Please enter a query:\n");
    scanf("%s", query);
    if (!strncmp(query, "03", 2) && strlen(query) == NO_LEN) {
        switch (query[2]) {
        case '0':
            printf("土木工程系\n");
            break;
        case '1':
            printf("自动化系\n");
            break;
        case 'W':
            printf("自动化系 留学生\n");
            break;
        default:
            printf("Query failed.\n");
        }
    }
    else {
        init_no_list(no_list);
        if (!strcmp(query, "自动化系"))
            count = get_count(no_list, "031") + get_count(no_list, "03W");
        else if (!strcmp(query, "土木系"))
            count = get_count(no_list, "030");
        else if (!strcmp(query, "中国"))
            count = get_count(no_list, "030") + get_count(no_list, "031");
        else if (!strcmp(query, "留学生"))
            count = get_count(no_list, "03W");
        else
            count = -1; // invalid input
        if (count != -1)
            printf("%d\n", count);
        else
            printf("Query failed.\n");
    }
    return 0;
}