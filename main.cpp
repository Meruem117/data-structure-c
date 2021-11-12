#include <iostream>
#include "include/list.h"

using namespace std;

int seqSearch(SeqList list, int key) {
    list.data[0] = key;
    int i;
    for (i = list.length; list.data[i] != key; i--);
    return i;
}

int main() {
    SeqList seqList{};
    initDefaultSeqList(seqList);
    printSeqList(seqList);
    cout << seqSearch(seqList, 1) << endl;
    return 0;
}
