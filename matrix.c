//
// Created by levas on 18.02.2023.
//

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h >

// Возвращает матрицу в динамической памяти  размером nRows на nCols.
Matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (Matrix) {values, nRows, nCols};
}

//освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(Matrix a) {
    for (int i = 0; i < a.nRows; i++)
        free(a.values[i]);
    free(a.values);
}

// размещает в динамической памяти массив из nMatrices матриц
// размером nRows на nCols. Возвращает указатель на нулевую матрицу.
Matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    Matrix *ms = (Matrix *) malloc(sizeof(Matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

//освобождает память, выделенную под хранение массива
// ms из nMatrices матриц.
void freeMemMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

//ввод матрицы m.
void inputMatrix(Matrix a) {
    for (int i = 0; i < a.nRows; i++)
        for (int j = 0; j < a.nCols; j++)
            scanf("%d", &a.values[i][j]);
}

//– вывод матрицы a.
void outputMatrix(Matrix a) {
    for (int i = 0; i < a.nRows; i++) {
        for (int j = 0; j < a.nCols; j++)
            printf("%d ", a.values[i][j]);
        printf("\n");
    }
}

//ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

//вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swap_pointers(int **a, int **b) {
    int *t = *a;
    *a = *b;
    *b = t;
}

// обмен строк с порядковыми номерами i1 и i2 в матрице a.
void swapRows(Matrix m, int i1, int i2) {
    assert(0 <= i1 && i1 < m.nRows);
    assert(0 <= i2 && i2 < m.nRows);

    swap_pointers(&m.values[i1], &m.values[i2]);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// обмен колонок с порядковыми номерами j1 и j2 в матрице a.
void swapColumns(Matrix m, int j1, int j2) {
    assert(0 <= j1 && j1 < m.nRows);
    assert(0 <= j2 && j2 < m.nRows);

    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2]);
}

// вычисление суммы элементов одномерного массива a размера n
int getSum(const int *a, int n) {
    int sum = a[0];
    for (int i = 1; i < n; i++)
        sum += a[i];
    return sum;
}

// выполняет сортировку вставками строк матрицы m
// по неубыванию значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteria(Matrix m,
                                          int (*criteria)(int *, int)) {
    int resultGetSum[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        resultGetSum[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        int t = resultGetSum[i];
        int j = i;
        while (j > 0 && resultGetSum[j - 1] > t) {
            resultGetSum[j] = resultGetSum[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        resultGetSum[j] = t;
    }
}

// выполняет сортировку выбором строк матрицы m по неубыванию значения
// функции criteria применяемой для столбцов
void selectionSortColsMatrixByColCriteria(Matrix m,
                                          int (*criteria)(int const *, int)) {
    int *criteriaValues = (int *) malloc(sizeof(int) * m.nCols);
    int *column = (int *) malloc(sizeof(int) * m.nRows);
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            column[i] = m.values[i][j];
        }
        criteriaValues[j] = criteria(column, m.nCols);
    }
    for (int i = 0; i < m.nCols; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (criteriaValues[j] < criteriaValues[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            swap(&criteriaValues[i], &criteriaValues[minIndex]);
            swapColumns(m, i, minIndex);
        }
    }
    free(column);
    free(criteriaValues);
}

// возвращает значение ’истина’, если матрица m
// является квадратной, ложь – в противном случае.
bool isSquareMatrix(Matrix m) {
    return m.nRows == m.nCols;
}

// возвращает значение ’истина’, если матрицы m1 и m2 равны,
// ложь – в противном случае
bool areTwoMatricesEqual(Matrix m1, Matrix m2) {
    bool isEqual = m1.nRows == m2.nRows && m1.nCols == m2.nCols ? true :
                   false;
    for (size_t i = 0; i < m1.nRows && isEqual; i++) {
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
            isEqual = false;
    }

    return isEqual;
}

//  возвращает значение ’истина’, если матрица m
//  является единичной, ложь – в противном случае.
bool iseMatrix(Matrix m) {
    if (m.nRows != m.nCols)
        return false;

    int n = m.nRows;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i == j) != m.values[i][j])
                return false;

    return true;
}

// возвращает значение ’истина’, если матрица m
// является симметричной, ложь – в противном случае.
bool isSymmetricMatrix(Matrix m) {
    if (isSquareMatrix(m)) {
        for (int i = 0; i < m.nRows; i++)
            for (int j = 0; j < m.nCols; j++)
                if (i != j && m.values[i][j] != m.values[j][i])
                    return false;
    } else
        return false;
    return true;
}

// транспонирует квадратную матрицу m.
void transposeSquareMatrix(Matrix m) {
    int position = 0;
    for (int i = position; i < m.nRows; i++) {
        for (int j = position; j < m.nCols; j++)
            if (i != j)
                swap(&m.values[i][j], &m.values[j][i]);
        position++;
    }
}

// транспонирует матрицу m.
void transposeMatrix(Matrix *m) {
    Matrix t = getMemMatrix(m->nCols, m->nRows);
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            t.values[j][i] = m->values[i][j];
    freeMemMatrix(*m);
    *m = t;
}

// возвращает матрицу размера nRows на nCols,
// построенную из элементов массива a
Matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    Matrix ms = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            ms.values[i][j] = a[k++];

    return ms;
}

//  возвращает указатель на нулевую матрицу массива
//  из nMatrices матриц, размещенных в динамической памяти,
//  построенных из элементов массива a
Matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols) {
    Matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

// возвращает позицию минимального элемента матрицы m.
Position getMinValuePos(Matrix m) {
    Position p = {0, 0};
    int minValue = m.values[0][0];
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                p.rowIndex = i;
                p.colIndex = j;
            }

    return p;
}

// возвращает позицию максимального элемента матрицы m.
Position getMaxValuePos(Matrix m) {
    Position p = {0, 0};
    int maxValue = m.values[0][0];
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > maxValue) {
                maxValue = m.values[i][j];
                p.rowIndex = i;
                p.colIndex = j;
            }

    return p;
}

int main() {

    int n = 3;
    int m = 2;

    Matrix a = getMemMatrix(n, m);

    inputMatrix(a);

    outputMatrix(a);

    freeMemMatrix(a);

    return 0;
}
