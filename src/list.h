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

void initSeqList(SeqList &list);

void initDefaultSeqList(SeqList &list);

void setSeqList(SeqList &list);

void printSeqList(SeqList list);

#endif //DATA_STRUCTURE_C_LIST_H
