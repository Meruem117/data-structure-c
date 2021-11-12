//
// Created by Meruem on 2021/11/10.
//

#ifndef DATA_STRUCTURE_C_LIST_H
#define DATA_STRUCTURE_C_LIST_H

#include "iostream"

using namespace std;

#define LIST_SIZE 10
struct SeqList {
    int data[LIST_SIZE];
    int length;
};

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

#endif //DATA_STRUCTURE_C_LIST_H
