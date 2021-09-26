#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "wheeee.h"
#include "loadingbar.h"
#include "messageOfTheDay.h"
#include "helper.h"
#include "matrix.h"

#define NUMBER_OF_OPTIONS 8
char dummyBuffer;

int main() {
    // init random
    // this is highly insecure but enough for this application
    // use /dev/urandom or equivalent for good randomness
    srand(time(NULL));

    printf("######################\n");
    printf("# CODING 101 LEVEL 1 #\n");
    printf("######################\n\n");
    //printRandoms(0, 6, 5);

    const char *options[NUMBER_OF_OPTIONS] = {
        "1) wheeee 1",
        "2) wheeee 2",
        "3) loading bar",
        "4) message of the day",
        "5) MATRIX",
        "",
        "0) exit",
        ""
    };

    printConst2Dchar(options, NUMBER_OF_OPTIONS);
    printf("Select: ");

    int selected = 0;
    scanf_s("%d", &selected);
    // something bug last enter is \r\n (on windows, might break anywhere else!) so we have to get rid of the \n in the buffer
    scanf_s("%c", &dummyBuffer);

    switch (selected) {
        case 0:
            showMessageOfTheDay(1);
            printf("and have a nice day <3");
            return 0;
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
            showMessageOfTheDay(0);
            break;
        case 5:
            drawMatrix();
            break;
        default:
            printf("Option '%d' is not available!", selected);
            break;
    }

    return 0;
}
