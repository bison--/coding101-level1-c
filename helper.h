//
// Created by Gamer on 26.09.2021.
//

#ifndef CODING101_HELPER_H
#define CODING101_HELPER_H

void printHashtag(int amount);
void printConst2Dchar(const char **ar, int rows);
void printChatAmount(int amount, char character);
void printRandoms(int lower, int upper, int count);
int getRandomRange(int min, int max);
void fillArrayWithValue(int *ar, int arrayLength, int value);
void arraySetValue(int *ar, int arrayLength, int value);
int arrayHasValue(int *ar, int arrayLength, int needle);
int getFreeRandomIndex(int *usedIndexes, int arrayLength);

#endif //CODING101_HELPER_H
