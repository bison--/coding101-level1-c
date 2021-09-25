#include <stdio.h>
#include <string.h>
#include "wheeee.h"

#define NUMBER_OF_OPTIONS 2

void print2Dchar(const char **, int rows);

int main() {
    const char *options[NUMBER_OF_OPTIONS] = {
        "1) wheeee 1",
        "2) wheeee 2"
    };

    print2Dchar(options, NUMBER_OF_OPTIONS);
    printf("Select: ");

    int selected = 0;
    scanf_s("%d", &selected);

    switch (selected) {
        case 1:
            wheeee_one();
            break;
        case 2:
            wheeee_two();
            break;
        default:
            printf("Option '%d' is not available!", selected);
            break;
    }

    return 0;
}

void print2Dchar(const char **ar, int rows) {
    for (int i = 0; i < rows; i ++) {
        printf("%s", ar[i]);
        printf("\n");
    }
}
