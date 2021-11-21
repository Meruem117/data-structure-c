//
// Created by Meruem on 2021/11/21.
//

#include "list.h"

void initSeqList(SeqList &list) {
    for (int &i: list.data) {
        i = 0;
    }
    list.length = 0;
}

void initDefaultSeqList(SeqList &list) {
    for (int i = 0; i < LIST_SIZE; i++) {
        list.data[i] = i;
    }
    list.length = LIST_SIZE;
}

void setSeqList(SeqList &list) {
    for (int &i: list.data) {
        cin >> i;
    }
    list.length = LIST_SIZE;
}

void printSeqList(SeqList list) {
    if (list.length == 0) {
        cout << "empty" << endl;
    }
    for (int i = 0; i < list.length; i++) {
        cout << list.data[i] << ' ';
    }
    cout << endl;
}
