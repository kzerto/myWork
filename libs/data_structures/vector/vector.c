#include <assert.h>
#include "stdio.h"
#include "malloc.h"
#include "vector.h"

vector createVector(size_t n) {
    int *v = (int *) malloc(sizeof(int) * n);
    if(v == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {v, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, newCapacity);
    if(v->data ==NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if (v->size > newCapacity)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

