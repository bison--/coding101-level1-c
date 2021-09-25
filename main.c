#include <stdio.h>
#include <string.h>
#include "wheeee.h"

#define NUMBER_OF_OPTIONS 2

void print2Dchar(const char **, int rows);
void print2DcharP(const char *ar);
int getRowsFromConst2Dchar(const char **ar);

int main() {
    const char *options[NUMBER_OF_OPTIONS] = {
            "1) wheeee 1",
            "2) wheeee 2",
            //NULL
    };
    //printf("%d", NUMBER_OF_OPTIONS);
    //printf("%d\n", strlen(options));
    print2Dchar(options, NUMBER_OF_OPTIONS);
    //print2DcharP(options);
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

int getRowsFromConst2Dchar(const char **ar) {
    // 'total' will be 70 = 10 * 7
    int total = sizeof(*ar);

    // 'column' will be 7 = size of first row
    int column = sizeof((*ar)[0]);

    // 'row' will be 10 = 70 / 7
    int rows = total / column;
    return rows;
}

void print2DcharP(const char *ar) {
    int number = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < number; i ++) {
        printf("%s", &(ar[i]));
        printf("\n");
    }
}
