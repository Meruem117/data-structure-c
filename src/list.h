//
// Created by Meruem on 2021/11/10.
//

#ifndef DATA_STRUCTURE_C_LIST_H
#define DATA_STRUCTURE_C_LIST_H

#include "iostream"

using namespace std;

#define LIST_SIZE 10

// data[0-9]
struct SeqList {
    int data[LIST_SIZE];
    int length;
};

// data[1-10]
struct SeqList2 {
    int data[LIST_SIZE + 1];
    int length;
};

void initSeqList(SeqList &list);

void initSeqList2(SeqList2 &list);

void initDefaultSeqList(SeqList &list);

void initDefaultSeqList2(SeqList2 &list);

void setSeqList(SeqList &list);

void setSeqList2(SeqList2 &list);

void printSeqList(SeqList list);

void printSeqList2(SeqList2 list);

#endif //DATA_STRUCTURE_C_LIST_H
