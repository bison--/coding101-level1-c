//
// Created by Gamer on 25.09.2021.
//

#include <stdio.h>
#include "wheeee.h"
#include "helper.h"

void wheeee_one() {
    printf("Enter MAX: ");
    int userNumber = 0;

#ifdef __unix__
    scanf("%d", &userNumber);
#else
    scanf_s("%d", &userNumber);
#endif

    for (int i = 0; i < userNumber; i++) {
        printHashtag(i + 1);
        printf("\n");
    }
}

void wheeee_two() {
    printf("Enter MAX: ");
    int userNumber = 0;

#ifdef __unix__
    scanf("%d", &userNumber);
#else
    scanf_s("%d", &userNumber);
#endif

    for (int i = 0; i < userNumber; i++) {
        printHashtag(i + 1);
        printf("\n");
    }

    for (int i = userNumber -1; i > 0; i--) {
        printHashtag(i);
        printf("\n");
    }
}
