//
// Created by Gamer on 26.09.2021.
//

#include <stdio.h>
#include <time.h>
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
