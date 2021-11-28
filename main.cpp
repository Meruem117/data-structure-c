#include <iostream>
#include "src/list.h"
#include "src/search.h"

using namespace std;

int main() {
    int key = 5;
    SeqList seqList{};
    SeqList2 seqList2{};

    initDefaultSeqList(seqList);
    printSeqList(seqList);
    initDefaultSeqList2(seqList2);
    printSeqList2(seqList2);

    cout << seqSearch(seqList, key) << endl;
    cout << binSearch(seqList, key) << endl;
    cout << seqSearchWithSentry(seqList2, key) << endl;
    return 0;
}
