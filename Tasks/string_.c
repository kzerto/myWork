//
// Created by levas on 12.03.2023.
//

#include "string_.h"
#include <corecrt.h>
#include <stdbool.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else

        fprintf(stderr, "%s - OK\n", funcName);
}

void getWordAlternation(char *s1, char *s2, char *destination) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            destination = copy(word1.begin, word1.end, destination);
            *destination = ' ';
            destination++;
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            destination = copy(word2.begin, word2.end, destination);
            *destination = ' ';
            destination++;
            beginSearch2 = word2.end;
        }
    }
    *(destination - 1) = '\0';
}
