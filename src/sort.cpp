//
// Created by Meruem on 2021/11/29.
//

#include "sort.h"
#include "utils.h"

void insertSort(int a[], int len) {
    int i, j, tmp;
    for (i = 1; i < len; i++) {
        if (a[i] < a[i - 1]) {
            tmp = a[i];
            for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = tmp;
        }
    }
    printArray(a, len, false);
}

void shellSort(int a[], int len) {
    int d, i, j;
    for (d = len / 2; d >= 1; d /= 2) {
        for (i = d + 1; i <= len; i++) {
            if (a[i] < a[i - d]) {
                a[0] = a[i];
                for (j = i - d; j > 0 && a[0] < a[j]; j -= d) {
                    a[j + d] = a[j];
                }
                a[j + d] = a[0];
            }
        }
    }
    printArray(a, len, true);
}

void bubbleSort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        bool flag = false;
        for (int j = len - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
    printArray(a, len, false);
}

int partition(int a[], int low, int high) {
    int p = a[low];
    while (low < high) {
        while (low < high && a[high] >= p) high--;
        a[low] = a[high];
        while (low < high && a[low] <= p) low++;
        a[high] = a[low];
    }
    a[low] = p;
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
