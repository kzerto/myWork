//
// Created by levas on 23.04.2023.
//

#ifndef UNTITLED1_VECTOR_H
#define UNTITLED1_VECTOR_H
#include <stdio.h>
#include <assert.h>
#include "malloc.h"

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;

} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

void test_popBack_notEmptyVector();

int* atVector(vector *v, size_t index);

int* back(vector *v);

int* front(vector *v);

void test_atVector_notEmptyVector();

void test_atVector_requestToLastElement();

void test_back_oneElementInVector();

void test_front_oneElementInVector();

#endif //UNTITLED1_VECTOR_H
