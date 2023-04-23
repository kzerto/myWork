//
// Created by levas on 06.01.2023.
//

#include "myFunction.h"
#include <stdio.h>
#include <malloc.h>

void inputArray(int *a, const size_t size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
}

void outputArray(int *a, const size_t size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");

}

int min2(int x, int y) {
    return x < y ? x : y;
}

long long power(int a, int n) {
    long long x = a;
    long long res = 1;
    while (n != 0) {
        if (n & 1)
            res *= x;
        n >>= 1;
        x = x * x;
    }

    return res;
}

int gcd(int a, int b) {
    while (a != 0 && b != 0)
        if (a > b)
            a = a % b;
        else
            b = b % a;

    return a + b;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int getMinIndex(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }

    return min - 1;
}

int isPrime(int n) {
    if (n > 1) {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return 0;
        return 1;
    } else {
        return 0;
    }
}

void universalSwap(void *a, void *b, size_t size) {
    char *pa = (char *) a;
    char *pb = (char *) b;
    for (size_t i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

int isSorted(const int *const a, int size) {
    for (int i = 1; i < size; i++)
        if (a[i - 1] > a[i])
            return 0;
    return 1;
}

size_t getFirstNegativeIndex(const int *a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        if (a[i] < 0)
            return i;
    return n;
}

int getSumOfDigits(long long x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int countSumOfDigitsX(const int *a, const size_t n,
                      const int digitsSum) {
    int count = 0;
    for (size_t i = 0; i < n; ++i)
        count += getSumOfDigits(a[i]) == digitsSum;
    return count;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

int getMaxEvenChainLen(const int *a, const size_t n) {
    int maxLen = 0;
    int currentLen = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            currentLen++;
            maxLen = max(maxLen, currentLen);
        } else {
            currentLen = 0;
        }
    }
    return maxLen;
}

void deleteNegative(int *a, size_t *n) {
    size_t iRead = 0;
    while (iRead < *n && a[iRead] >= 0)
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (a[iRead] >= 0) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void insert(int *a, size_t *n, const size_t pos, const int value) {
    for (size_t i = *n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = value;

    (*n)++;
}

//Рекурсии

int fib(int n) {
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int isPalindrome_(const int *a, int left, int right) {
    if (left < right) {
        return a[left] == a[right] && isPalindrome_(a, left + 1, right - 1);
    } else {
        return 1;
    }
}

int getSum(const int *a, int left, int right) {
    int n = right - left;
    if (!n) {
        return 0;
    } else {
        return a[left] + getSum(a, left + 1, right);
    }
}

void selectionSort_(int *unsortedPart, int nUnsorted) {
    if (nUnsorted == 1) {

        return;
    } else {
        int minElementIndex = getMinIndex(unsortedPart, nUnsorted);
        swap(&unsortedPart[0], &unsortedPart[minElementIndex]);
        selectionSort_(unsortedPart + 1, nUnsorted - 1);
    }
}

static void deleteIf_(int *a, int (deleteCondition)(int),
                      int *size, int iRead, int iWrite) {
    if (iRead == *size) {
        *size = iWrite;
        return;
    } else {
        a[iWrite] = a[iRead];
        iWrite++;
    }
    deleteIf_(a, deleteCondition, size, iRead + 1, iWrite);
}

void deleteIf(int *a, int *n, int (*deleteCondition)(int)) {
    deleteIf_(a, deleteCondition, n, 0, 0);
}

static int binarySearch(const int *a, int x, int right, int left) {
    if (left > right)
        return -1;

    int middle = (left + right) / 2;
    if (a[middle] == x) {
        return middle;
    } else if (a[middle] < x) {
        return binarySearch_(a, x, right, middle + 1);
    } else {
        return binarySearch_(a, x, middle - 1, left);
    }
}

int binarySearch_(const int *a, int n, int x) {
    return binarySearch_(a, x, n - 1, 0);
}

//Линейный поиск в отсортированном массиве
size_t linearSearch(const int *a, const size_t n, int x) {
    size_t i = 0;
    while (i < n && a[i] < x)
        i++;
    return i < n;
}

//Линейный поиск в неотсортированном массиве
size_t linearFindFast(int *a, const size_t n, const int x) {
    a[n] = x;

    size_t i = 0;
    while (a[i] != x)
        i++;

    return i;
}

//Сортировки

void selectionSort(int *a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minPos])
                minPos = j;
            swap(&a[i], &a[minPos]);
        }
    }
}

void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = size - 1; j > i; j--) {
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
        }
    }
}

void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size ; ++i, ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
        }
    }
}

void getMinMax(const int *a, size_t size, int *min, int *max) {
    *min = a[0];
    *max = a[0];

    for (int i = 1; i < size; i++) {
        if (a[i] < *min) {
            *min = a[i];
        } else if (a[i] > *max) {
            *max = a[i];
        }
    }
}

void countSort(int *a, const size_t size) {
    int min, max;
    getMinMax(a, size, &min, &max);
    int k = max - min + 1;

    int *b = (int *) calloc(k, sizeof(int));
    for (int i = 0; i < size; i++) {
        b[a[i] - min]++;
    }

    int ind = 0;
    for (int i = 0; i < k; i++) {
        int x = b[i];
        for (int j = 0; j < x; j++) {
            a[ind++] = min + i;
        }
    }

    free(b);
}