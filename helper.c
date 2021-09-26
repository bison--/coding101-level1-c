//
// Created by Gamer on 26.09.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void printHashtag(int amount) {
    for (int i = 0; i < amount; i++) {
        printf("#");
    }
}

void printChatAmount(int amount, char character) {
    for (int i = 0; i < amount; i++) {
        printf("%c", character);
    }
}

void printConst2Dchar(const char **ar, int rows) {
    for (int i = 0; i < rows; i ++) {
        printf("%s", ar[i]);
        printf("\n");
    }
}

// Generates and prints 'count' random
// numbers in range [lower, upper].
void printRandoms(int lower, int upper, int count) {
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
                   (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
}

int getRandomRange(int min, int max) {
    int num = (rand() % ((max -1) - min + 1)) + min;
    //printf("random: %d ", num);
    return num;
}

void fillArrayWithValue(int *ar, int arrayLength, int value) {
    for (int i = 0; i < arrayLength; i++) {
        ar[i] = value;
    }
}

void arraySetValue(int *ar, int arrayLength, int value) {
    for (int i = 0; i < arrayLength; i++) {
        if (ar[i] == -1) {
            ar[i] = value;
            break;
        }
    }
}

int arrayHasValue(int *ar, int arrayLength, int needle) {
    for (int i = 0; i < arrayLength; i++) {
        if (ar[i] == needle) {
            return 1;
        }
    }

    return 0;
}

int getFreeRandomIndex(int *usedIndexes, int arrayLength) {
    int hasFreeSlots = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (usedIndexes[i] == -1) {
            hasFreeSlots++;
        }
    }

    if (hasFreeSlots == 0) {
        printf("> RESET\n");
        fillArrayWithValue(usedIndexes, arrayLength, -1);
    }

    int randomIndex = getRandomRange(0, arrayLength);
    while (arrayHasValue(usedIndexes, arrayLength, randomIndex)) {
        randomIndex = getRandomRange(0, arrayLength);
    }

    arraySetValue(usedIndexes, arrayLength, randomIndex);

    return randomIndex;
}
