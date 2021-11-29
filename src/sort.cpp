//
// Created by Meruem on 2021/11/29.
//

#include "sort.h"

void printArray(int a[], int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

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
    printArray(a, len);
}
