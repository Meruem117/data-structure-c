#include <iostream>
#include "src/list.h"
#include "src/search.h"

using namespace std;

int main() {
    SeqList seqList{};
    SeqList2 seqList2{};

    initDefaultSeqList(seqList);
    printSeqList(seqList);
    cout << seqSearch(seqList, 1) << endl;

    initDefaultSeqList2(seqList2);
    printSeqList2(seqList2);
    cout << seqSearchWithSentry(seqList2, 1) << endl;
    return 0;
}
