//
// Created by levas on 06.01.2023.
//

#ifndef UNTITLED1_MYFUNCTION_H
#define UNTITLED1_MYFUNCTION_H

#include <corecrt.h>

void inputArray(int *a, const size_t size);

void outputArray(int *a, const size_t size);

int max2(int a, int b);

int min2(int x, int y);

long long power(int a, int n);

int gcd(int a, int b);

void swap(int *a, int *b);

int getMinIndex(int *a, int n);

int isPrime(int n);

void universalSwap(void *a, void *b, size_t size);

int isSorted(const int * const a, int size);

void getMinMax(const int *a, size_t size, int *min, int *max);

size_t getFirstNegativeIndex(const int *a, const size_t n);

int getSumOfDigits(long long x);

int countSumOfDigitsX(const int *a, const size_t n,
                      const int digitsSum);

int getMaxEvenChainLen(const int *a, const size_t n);

void deleteNegative(int *a, size_t *n);

void insert(int *a, size_t *n, const size_t pos, const int value);

//Рекурсии

int fib(int n);

int getSum(const int *a, int left, int right);

int isPalindrome_(const int *a, int left, int right);

void selectionSort_(int *unsortedPart, int nUnsorted);

void deleteIf(int *a, int *n, int (*deleteCondition)(int));

int binarySearch_(const int *a, int n, int x);

//Линейный поиск

size_t linearSearch(const int *a, const size_t n, int x);

size_t linearFindFast(int *a, const size_t n, const int x);

//Сортировки

void selectionSort(int *a, const int size);

void insertionSort(int *a, const size_t size);

void bubbleSort(int *a, size_t size);

void combsort(int *a, const size_t size);

void countSort(int *a, const size_t size);

#endif //UNTITLED1_MYFUNCTION_H
