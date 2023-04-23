#include <assert.h>
#include "stdio.h"
#include "malloc.h"
#include "vector.h"
#include <stdbool.h>

vector createVector(size_t n) {
    int *v = (int *) malloc(sizeof(int) * n);
    if (v == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {v, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, newCapacity);
    if (v->data == NULL) {
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

bool isEmpty(vector *v) {
    return (v->size == 0 ? true : false);
}

bool isFull(vector *v) {
    return (v->size == v->capacity ? true : false);
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, 1);
        v->data[0] = x;
        v->size++;
    } else if (isFull(v)) {
        reserve(v, v->capacity * 2);
        v->data[v->size] = x;
        v->size++;
    } else {
        v->data[v->size] = x;
        v->size++;
    }
}

void test_pushBank_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    assert(v.capacity == 1);
    assert(v.size == 1);
    assert(v.data[v.size - 1] == 42);
}

void test_pushBank_fullVector() {
    vector v = createVector(42);
    v.size = 12;
    pushBack(&v, 42);
    assert(v.capacity == 25);
    assert(v.size == 12);
    assert(v.data[v.size - 1] == 42);
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        v->size--;
    }
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

int *atVector(vector *v, size_t index) {
    if (v->size <= index) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", index);
        exit(1);
    }
    int *a = v->data + index;

    return a;
}

int *back(vector *v) {
    return atVector(v, v->size - 1);
}

int *front(vector *v) {
    return atVector(v, 0);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(12);
    for (int i = 0; i <= 11; i++) {
        v.data[i] = i;
    }
    v.size = 12;
    int *a = atVector(&v, 6);
    assert(*a == 6);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(15);
    for (int i = 0; i <= 14; i++) {
        v.data[i] = i;
    }
    v.size = 15;
    int *a = atVector(&v, 14);
    assert(*a == 14);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.data[0] = 42;
    v.size = 1;
    int *a = back(&v);
    assert(*a == 42);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.data[0] = 31;
    v.size = 1;
    int *a = front(&v);
    assert(*a == 31);
}
