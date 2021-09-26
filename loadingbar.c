//
// Created by Gamer on 26.09.2021.
//

#include <stdio.h>
#include "loadingbar.h"
#include "helper.h"

void execLoadingBar() {
    int userNumber = 0;
    printf("Enter State: ");
#ifdef __unix__
    scanf("%d", &userNumber);
#else
    scanf_s("%d", &userNumber);
#endif
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
