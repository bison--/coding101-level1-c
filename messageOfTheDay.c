//
// Created by Gamer on 26.09.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include "messageOfTheDay.h"
#include "helper.h"

void fillArrayWithValue(int *ar, int arrayLength, int value);
int arrayHasValue(int *ar, int arrayLength, int needle);
int getFreeRandomIndex(int *usedIndexes, int arrayLength);
void arraySetValue(int *ar, int arrayLength, int value);

void showMessageOfTheDay() {
    const int messageAmount = 6;
    const char* messages[] = {
        "No one is perfect - that’s why pencils have erasers.\n - Wolfgang Riebe",
        "Have no fear of perfection - you'll never reach it.\n - Salvador Dali",
        "The tallest mountain started as a stone.\n - One Punch Man Intro",
        "Make it work. Make it nice. Make it fast. Always obey this order!\n - kiraa",
        "A good programmer is someone who always looks both ways before crossing a one-way street.\n - Doug Linder",
        "If debugging is the process of removing software bugs, then programming must be the process of putting them in.\n - Edsger W. Dijkstra",
    };

    int *usedIndexes;
    usedIndexes = (int *)calloc(messageAmount, sizeof(int));
    //usedIndexes = (int *)malloc(messageAmount * sizeof(int));
    fillArrayWithValue(usedIndexes, messageAmount, -1);

    char userInput;
    scanf_s("%c", &userInput); // something bug last enter is \r\n so we have to get rid of the \n in the buffer

    int keepRunning = 1;
    while (keepRunning) {
        int randomIndex = getFreeRandomIndex(usedIndexes, messageAmount);

        printf("%s\n", messages[randomIndex]);

        printf("> For more press enter, to quit q\n");
        scanf_s("%c", &userInput);

        if (userInput == 'q') {
            keepRunning = 0;
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

void fillArrayWithValue(int *ar, int arrayLength, int value) {
    for (int i = 0; i < arrayLength; i++) {
        ar[i] = value;
    }
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

void arraySetValue(int *ar, int arrayLength, int value) {
    for (int i = 0; i < arrayLength; i++) {
        if (ar[i] == -1) {
            ar[i] = value;
            break;
        }
    }
}
