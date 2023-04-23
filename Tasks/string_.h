//
// Created by levas on 12.03.2023.
//

#ifndef UNTITLED1_STRING__H
#define UNTITLED1_STRING__H
#include <corecrt.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

size_t strLen(const char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif //UNTITLED1_STRING__H
