#include <stdio.h>
#include <string.h>
#define MAXLEN 20

int main() {
    char input;
    char output[MAXLEN];
    scanf("%c", &input);
    input = toupper(input);
    if (input == 'A')
        strcpy(output, "85-100");
    else if (input == 'B')
        strcpy(output, "70-84");
    else if (input == 'C')
        strcpy(output, "60-69");
    else if (input == 'D')
        strcpy(output, "0-59");
    else
        strcpy(output, "Invalid input.");
    printf("%s\n", output);
    return 0;
}