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

void showMessageOfTheDay(int showOne) {
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

    int keepRunning = 1;
    while (keepRunning) {
        int randomIndex = getFreeRandomIndex(usedIndexes, messageAmount);

        printf("%s\n", messages[randomIndex]);
        if (showOne) {
            return;
        }

        printf("> For more press enter, to quit q\n");
        scanf_s("%c", &userInput);

        if (userInput == 'q') {
            keepRunning = 0;
        }
    }
}
