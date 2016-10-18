/*
Author: Lu Yiwen
ID: 2015011443
Date: 2015-10-13
Description: Given a numerical sequence str1, turn it into str2 in
             capitalize Chinese.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXLEN 100

// use an ugly hack to deal with Chinese encoding issues
#define CHN_0 10
#define CHN_1 11
#define CHN_2 12
#define CHN_3 13
#define CHN_4 14
#define CHN_5 15
#define CHN_6 16
#define CHN_7 17
#define CHN_8 18
#define CHN_9 19
#define CHN_1E1 20
#define CHN_1E2 21
#define CHN_1E3 22
#define CHN_1E4 23
#define CHN_1E8 24

void put_chn_char(char* dest, char c)
{
    switch (c) {
    case CHN_0:
        strcat(dest, "零");
        break;
    case CHN_1:
        strcat(dest, "壹");
        break;
    case CHN_2:
        strcat(dest, "贰");
        break;
    case CHN_3:
        strcat(dest, "叁");
        break;
    case CHN_4:
        strcat(dest, "肆");
        break;
    case CHN_5:
        strcat(dest, "伍");
        break;
    case CHN_6:
        strcat(dest, "陆");
        break;
    case CHN_7:
        strcat(dest, "柒");
        break;
    case CHN_8:
        strcat(dest, "捌");
        break;
    case CHN_9:
        strcat(dest, "玖");
        break;
    case CHN_1E1:
        strcat(dest, "拾");
        break;
    case CHN_1E2:
        strcat(dest, "百");
        break;
    case CHN_1E3:
        strcat(dest, "千");
        break;
    case CHN_1E4:
        strcat(dest, "万");
        break;
    case CHN_1E8:
        strcat(dest, "亿");
        break;
    }
}

void print_chn_str(char* dest, char* s)
{
    int i;
    dest[0] = '\0'; // reset destination string
    for (i = 0; i < strlen(s); ++i)
        put_chn_char(dest, s[i]);
}

void append(char* s, char c)
{
    // append c to the end of s
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

int e(int n)
{
    // 10 ^ n
    int i, e;
    e = 1;
    for (i = 0; i < n; ++i)
        e *= 10;
    return e;
}

char* read_4_rec(int x, int n, int silent1)
{
    /*
    n indicates to which digit the number should be read,
    e.g. read_4_rec(1, 1, 0) reads 壹, while read_4_rec(1, 2, 0) ,read_4_rec(1, 3, 0)
         and read_4_rec(1, 4, 0) all read 零壹.
    The first 壹 is omitted if silent1 is set.
    e.g. read_4_rec(11, 2, 1) reads 拾壹 instead of 壹拾壹.
    */
    const char postfix[] = {'\0', '\0', CHN_1E1, CHN_1E2, CHN_1E3}; // 拾, 百, 千
    const char digits[] = {CHN_0, CHN_1, CHN_2, CHN_3, CHN_4, CHN_5, CHN_6,
                           CHN_7, CHN_8, CHN_9
                          };    // from 零 to 玖
    char chn[MAXLEN] = "\0";
    int first_digit = x / e(n - 1);
    int next_n = n - 1;
    if (x == 0)
        return "\0";
    if (first_digit) {
        // e.g. when x = 1001, n = 4, the first 1 is read as 壹千.
        if (!(silent1 && first_digit == 1))
            append(chn, digits[first_digit]);
        append(chn, postfix[n]);
    } else {
        // read 零 and skip all the remaining zeros
        append(chn, digits[0]);
        next_n = ceil(log(x + 0.5) / log(10));
    }
    if (n > 1)
        strcpy(chn + strlen(chn), read_4_rec(x % e(n - 1), next_n, silent1));
    return chn;
}

char* read_4(int x, int withzero)
{
    /*
    Read an integer x (0 < x <= 9999) into a Chinese string.
    For 0 < x <= 999, withzero indicates whether to read zero before the number,
    e.g. read_4(1, 0) reads 壹, while read_4(1, 1) reads 零壹.
    */
    if (withzero)
        return read_4_rec(x, 4, 0);
    if (10 <= x && x <= 19)
        return read_4_rec(x, ceil(log(x + 0.5) / log(10)), 1);
    return read_4_rec(x, ceil(log(x + 0.5) / log(10)), 0);
}

char* read(long long x)
{
    // Read an integer x (0 < x <= 1e10) into a Chinese string.
    const char postfix[] = {CHN_1E8, CHN_1E4, '\0'};
    char chn[MAXLEN] = "\0";
    int base1e4[3]; // cut x, 4 digits a group
    int i;
    /* If non-zero number has appeared in higher places,
    lower places should be prefixed with zero when reading.*/
    int withzero = 0;
    if (x == 0) {
        append(chn, CHN_0);
        return chn;
    }
    base1e4[0] = x / 1E8;
    base1e4[1] = (x - base1e4[0] * 1E8) / 1E4;
    base1e4[2] = x - base1e4[0] * 1E8 - base1e4[1] * 1E4;
    for (i = 0; i <= 2; ++i) {
        if (base1e4[i] == 0) {
            if (i == 1 && base1e4[0] != 0 && base1e4[2] != 0) {
                append(chn, CHN_0);
                withzero = 0;   // no more zero need to be read for 1e0
            }
        } else {
            strcpy(chn + strlen(chn), read_4(base1e4[i], withzero));
            withzero = 1;
            append(chn, postfix[i]);
        }
    }
    return chn;
}

void unittest()
{
    char test_result[MAXLEN];
    char dest[MAXLEN];
    int i;

    // test case for read_4
    const int testcase1[15] = {1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011,
                               1100, 1101, 1110, 1111
                              };

    // test case for read
    const long long testcase2[8] = {0, 123, 1230000, 1230123, 12300000000, 12300000123,
                                    12301230000, 12345678901
                                   };

    for (i = 0; i < 15; ++i) {
        strcpy(test_result, read_4(testcase1[i], 0));
        print_chn_str(dest, test_result);
        printf("%s\n", dest);
        strcpy(test_result, read_4(testcase1[i], 1));
        print_chn_str(dest, test_result);
        printf("%s\n", dest);
    }
    printf("\n\n");

    for (i = 0; i < 8; ++i) {
        strcpy(test_result, read(testcase2[i]));
        print_chn_str(dest, test_result);
        printf("%s\n", dest);
    }
}

int main()
{
    char str1[MAXLEN], str2[MAXLEN], result[MAXLEN];
    long long num = 0;
    int i;
    // unittest();
    gets(str1);
    for (i = 0; i < strlen(str1); ++i)
        num = 10 * num + (str1[i] - '0');
    strcpy(result, read(num));
    print_chn_str(str2, result);
    printf("%s\n", str2);
    return 0;
}
