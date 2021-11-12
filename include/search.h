//
// Created by Meruem on 2021/11/12.
//

#ifndef DATA_STRUCTURE_C_SEARCH_H
#define DATA_STRUCTURE_C_SEARCH_H

#include "list.h"

int seqSearch(SeqList list, int key) {
    int i;
    list.data[0] = key;
    for (i = list.length; list.data[i] != key; i--);
    return i;
}

int binSearch(SeqList list, int key) {
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

#endif //DATA_STRUCTURE_C_SEARCH_H
