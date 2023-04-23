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


#endif //UNTITLED1_VECTOR_H
