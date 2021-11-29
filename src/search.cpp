//
// Created by Meruem on 2021/11/21.
//

#include "search.h"

int seqSearch(List list, int key) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == key) {
            return i;
        }
    }
    return -1;
}

int seqSearchWithSentry(List list, int key) {
    int i;
    list.data[0] = key;
    for (i = list.length; list.data[i] != key; i--);
    return i;
}

int binSearch(List list, int key) {
    int low = 0, high = list.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (list.data[mid] == key) {
            return mid;
        } else if (list.data[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
