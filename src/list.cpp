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

void initSeqList2(SeqList2 &list) {
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

void initDefaultSeqList2(SeqList2 &list) {
    list.data[0] = 0;
    for (int i = 1; i < LIST_SIZE + 1; i++) {
        list.data[i] = i - 1;
    }
    list.length = LIST_SIZE;
};

void setSeqList(SeqList &list) {
    for (int &i: list.data) {
        cin >> i;
    }
    list.length = LIST_SIZE;
}

void setSeqList2(SeqList2 &list) {
    for (int &i: list.data) {
        cin >> i;
    }
    list.length = LIST_SIZE;
}

void printSeqList(SeqList list) {
    if (list.length == 0) {
        cout << "empty" << endl;
    } else {
        for (int i = 0; i < list.length; i++) {
            cout << list.data[i] << ' ';
        }
        cout << endl;
    }
}

void printSeqList2(SeqList2 list) {
    if (list.length == 0) {
        cout << "empty" << endl;
    } else {
        for (int i = 0; i <= list.length; i++) {
            cout << list.data[i] << ' ';
        }
        cout << endl;
    }
};
