#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "wheeee.h"
#include "loadingbar.h"
#include "messageOfTheDay.h"
#include "helper.h"

#define NUMBER_OF_OPTIONS 4

void print2Dchar(const char **, int rows);
void printHashtag(int amount);

int main() {
    // init random
    srand(time(NULL));

    printf("######################\n");
    printf("# CODING 101 Level 1 #\n");
    printf("######################\n\n");
    //printRandoms(0, 6, 5);

    const char *options[NUMBER_OF_OPTIONS] = {
        "1) wheeee 1",
        "2) wheeee 2",
        "3) loading bar",
        "4) message of the day"
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
        case 3:
            execLoadingBar();
            break;
        case 4:
            showMessageOfTheDay();
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

