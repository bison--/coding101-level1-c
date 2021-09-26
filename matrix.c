//
// Created by Gamer on 26.09.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "helper.h"

void drawMatrix() {
    int rows;
    int cols;
    int randomAmount;

#ifdef __unix__
    printf("\nWidth: ");
    scanf("%d", &cols);

    printf("\nHeight: ");
    scanf("%d", &rows);

    printf("\nRandoms: ");
    scanf("%d", &randomAmount);
#else
    printf("\nWidth: ");
    scanf_s("%d", &cols);

    printf("\nHeight: ");
    scanf_s("%d", &rows);

    printf("\nRandoms: ");
    scanf_s("%d", &randomAmount);
#endif



    int fieldsTotal = rows * cols;
    if (randomAmount > fieldsTotal) {
        printf("\nERROR: more randoms than fields!");
        return;
    }

    int *randomIndexes;
    randomIndexes = (int *)calloc(randomAmount, sizeof(int));

    fillArrayWithValue(randomIndexes, fieldsTotal, -1);
    for (int i = 0; i < randomAmount; i++) {
        int newRandom = getRandomRange(0, fieldsTotal);
        while (arrayHasValue(randomIndexes, fieldsTotal, newRandom)) {
            newRandom = getRandomRange(0, fieldsTotal);
        }
        randomIndexes[i] = newRandom;
    }

    for (int i = 0; i < fieldsTotal; i++) {
        if (arrayHasValue(randomIndexes, fieldsTotal, i)) {
            printf("*");
        } else {
            printf("#");
        }

        if ((i + 1) % cols == 0) {
            printf("\n");
        }
    }
}
