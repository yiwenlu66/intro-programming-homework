#include <stdio.h>
#define OUT 0
#define IN 1
#define MAXLEN 30

int main() {
    int state;
    char dict[MAXLEN][MAXLEN];
    char c;
    int wc, wl;   // word count and the current word length
    int i;
    wc = wl = 0;
    state = OUT;
    printf("Please input a string (less than 30 characters):\n");
    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            if (state == IN) {
                state = OUT;
                dict[wc++][wl] = '\0';
                wl = 0;
            }
        }
        else {
            state = IN;
            dict[wc][wl++] = c;
        }
    }
    if (state == IN)
        dict[wc++][wl] = '\0';
    printf("There are %d words:\n", wc);
    for (i = 0; i < wc; ++i)
        printf("%s\n", dict[i]);
    return 0;
}