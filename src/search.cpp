//
// Created by Meruem on 2021/11/21.
//

#include "search.h"

int seqSearch(int a[], int len, int key) {
    for (int i = 0; i < len; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int seqSearchWithSentry(int a[], int len, int key) {
    int i;
    a[0] = key;
    for (i = len; a[i] != key; i--);
    return i;
}

int binSearch(int a[], int len, int key) {
    int low = 0, high = len - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
