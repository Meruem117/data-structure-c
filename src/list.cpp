//
// Created by Meruem on 2021/11/21.
//

#include "list.h"
#include "iostream"

using namespace std;

void initList(List &list) {
    list.data = {};
    list.length = 0;
}

void setList(List &list, int *data, int length) {
    list.data = data;
    list.length = length;
}

void printList(List list) {
    if (list.length == 0) {
        cout << "empty list" << endl;
    } else {
        for (int i = 0; i < list.length; i++) {
            cout << list.data[i] << ' ';
        }
        cout << endl;
    }
}
