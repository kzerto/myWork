//
// Created by levas on 18.02.2023.
//

#ifndef UNTITLED1_MATRIX_H
#define UNTITLED1_MATRIX_H
#include <stdbool.h>

typedef struct Matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} Matrix;

typedef struct Position {
    int rowIndex;
    int colIndex;
} Position;

Matrix getMemMatrix(int nRows, int nCols);

Matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(Matrix a);

void freeMemMatrices(Matrix *ms, int nMatrices);

void inputMatrix(Matrix a);

void inputMatrices(Matrix *ms, int nMatrices);

void outputMatrix(Matrix a);

void outputMatrices(Matrix *ms, int nMatrices);

void swap_pointers(int **a, int **b);

void swapRows(Matrix a, int i1, int i2);

void swap(int *a, int *b);

void swapColumns(Matrix a, int j1, int j2);

int getSum(const int *a, int n);

void insertionSortRowsMatrixByRowCriteria(Matrix m,
                                          int (*criteria)(int *, int));

void selectionSortColsMatrixByColCriteria(Matrix m,
                                          int (*criteria)(int const *, int));

bool isSquareMatrix(Matrix m);

bool areTwoMatricesEqual(Matrix m1, Matrix m2);

bool isEMatrix(Matrix m);

bool isSymmetricMatrix(Matrix m);

void transposeSquareMatrix(Matrix m);

void transposeMatrix(Matrix *m);

Position getMinValuePos(Matrix m);

Position getMaxValuePos(Matrix m);

Matrix createMatrixFromArray(const int *a, int nRows, int nCols);

Matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols);


#endif //UNTITLED1_MATRIX_H
