//
// Created by Meruem on 2021/11/10.
//

#ifndef DATA_STRUCTURE_C_LIST_H
#define DATA_STRUCTURE_C_LIST_H

#include "iostream"

using namespace std;

struct List {
    int *data;
    int length;
};

void initList(List &list);

void setList(List &list, int *data, int length);

void printList(List list, bool hasHead);

#endif //DATA_STRUCTURE_C_LIST_H
