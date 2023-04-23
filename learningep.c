
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "myFunction.h"
#include <stdint.h>
#include <memory.h>
#include <malloc.h>
#include <stdio.h>
#include <corecrt.h>

#define ARRAY_SIZE(ARR) (sizeof(ARR) / sizeof(*ARR))

#define SET(ARR) ((SetAnOrderedArray) {(ARR), ARRAY_SIZE(ARR)})

typedef struct SetAnOrderedArray {
    int *data;           // Элементы множества
    int power;           // Текущая мощность множества
} SetAnOrderedArray;

static void addElement(SetAnOrderedArray *set, const int val) {
    set->data[set->power] = val;
    set->power++;
}

void printset(FILE *out, const SetAnOrderedArray set) {
    fprintf(out, "{");
    if (set.power) {
        for (size_t i = 0; i < set.power - 1; i++) {
            fprintf(out, "%d, ", set.data[i]);
        }
        fprintf(out, "%d", set.data[set.power - 1]);
    }
    fprintf(out, "}");
}

// Объединение множеств
void unionSets(SetAnOrderedArray set1,
               SetAnOrderedArray set2,
               SetAnOrderedArray *outSet) {
    outSet->power = 0;
    size_t iSet1 = 0;
    size_t iSet2 = 0;
    while (iSet1 < set1.power && iSet2 < set2.power) {
        if (set1.data[iSet1] < set2.data[iSet2]) {
            addElement(outSet, set1.data[iSet1++]);
        } else if (set1.data[iSet1] == set2.data[iSet2]) {
            addElement(outSet, set1.data[iSet1++]);
            iSet2++;
        } else {
            addElement(outSet, set2.data[iSet2++]);
        }
    }
    while (iSet1 < set1.power) {
        addElement(outSet, set1.data[iSet1++]);
    }
    while (iSet2 < set2.power) {
        addElement(outSet, set2.data[iSet2++]);
    }
}

// Разность множеств
void differenceSets(SetAnOrderedArray set1,
                    SetAnOrderedArray set2,
                    SetAnOrderedArray *outSet) {
    outSet->power = 0;
    size_t iSet1 = 0;
    size_t iSet2 = 0;
    while (iSet1 < set1.power && iSet2 < set2.power) {
        if (set1.data[iSet1] == set2.data[iSet2]) {
            iSet1++;
            iSet2++;
        } else if (set1.data[iSet1] < set2.data[iSet2]) {
            addElement(outSet, set1.data[iSet1++]);
        } else {
            iSet2++;
        }
    }
    while (iSet1 < set1.power) {
        addElement(outSet, set1.data[iSet1++]);
    }
}

// Пересечение множеств на упорядоченных массивах
// set1 и set2 в множестве outSet
void intersectionSets(SetAnOrderedArray set1,
                      SetAnOrderedArray set2,
                      SetAnOrderedArray *outSet) {
    outSet->power = 0;
    size_t iSet1 = 0;
    size_t iSet2 = 0;
    while (iSet1 < set1.power && iSet2 < set2.power) {
        if (set1.data[iSet1] == set2.data[iSet2]) {
            addElement(outSet, set1.data[iSet1++]);
            iSet2++;
        } else if (set1.data[iSet1] < set2.data[iSet2]) {
            iSet1++;
        } else {
            iSet2++;
        }
    }
}


// вывод элементов множества
void outputSet(const SetAnOrderedArray set, const char *setName) {
    printf("%s = ", setName);
    printset(stdout, set);
}

int main() {
    int a[] = {1, 2, 3, 8};
    int b[] = {3, 5, 6, 7};
    int c[] = {2, 3, 4, 7};
    SetAnOrderedArray A = SET(a);
    SetAnOrderedArray B = SET(b);
    SetAnOrderedArray C = SET(c);

    int d1[25] = {};
    SetAnOrderedArray D1 = SET(d1);
    intersectionSets(A, B, &D1);

    int d2[25] = {};
    SetAnOrderedArray D2 = SET(d2);
    differenceSets(A, C, &D2);

    int d3[25] = {};
    SetAnOrderedArray D3 = SET(d3);
    differenceSets(B, C, &D3);

    int d4[25] = {};
    SetAnOrderedArray D4 = SET(d4);
    unionSets(D1, D2, &D4);

    int d[25] = {};
    SetAnOrderedArray D = SET(d);
    unionSets(D4, D3, &D);

    outputSet(D, "D");
    printf("\n");

    return 0;
}
