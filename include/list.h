//
// Created by Meruem on 2021/11/10.
//

#ifndef DATA_STRUCTURE_C_LIST_H
#define DATA_STRUCTURE_C_LIST_H

#include "iostream"

using namespace std;

#define MAX_SIZE 10
struct SeqList {
    int data[MAX_SIZE];
    int length;
};

void initSeqList(SeqList &list) {
    for (int &i: list.data) {
        i = 0;
    }
    list.length = 0;
}

void setSeqList(SeqList &list) {
    for (int &i: list.data) {
        cin >> i;
    }
    list.length = MAX_SIZE;
}

void printSeqList(SeqList list) {
    if (list.length == 0) {
        cout << "empty" << endl;
    }
    for (int i = 0; i < list.length; i++) {
        cout << list.data[i] << ' ';
    }
}

#endif //DATA_STRUCTURE_C_LIST_H
