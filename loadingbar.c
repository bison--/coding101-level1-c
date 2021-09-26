//
// Created by Gamer on 26.09.2021.
//

#include <stdio.h>
#include "loadingbar.h"
#include "helper.h"

void execLoadingBar() {
    int userNumber = 0;
    printf("Enter State: ");
    scanf_s("%d", &userNumber);
    int userNumberNormal = userNumber / 10;

    for (int i = userNumberNormal; i <= 10; i++) {
        printf("[");
        printHashtag(i);
        printCharAmount(10 - i, ' ');

        if (i == 0) {
            printf("]  0%% \n");
        } else {
            printf("] %d0%% \n", i);
        }
    }
}
