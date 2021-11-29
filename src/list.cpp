//
// Created by Meruem on 2021/11/21.
//

#include "list.h"

void initList(List &list) {
    list.data = {};
    list.length = 0;
}

void setList(List &list, int *data, int length) {
    list.data = data;
    list.length = length;
}

void printList(List list, bool hasHead) {
    if (list.length == 0) {
        cout << "empty list" << endl;
        return;
    }
    if (hasHead) {
        for (int i = 0; i <= list.length; i++) {
            cout << list.data[i] << ' ';
        }
    } else {
        for (int i = 0; i < list.length; i++) {
            cout << list.data[i] << ' ';
        }
    }
    cout << endl;
}
