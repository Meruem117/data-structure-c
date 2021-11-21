#include <iostream>
#include "src/list.h"
#include "src/search.h"

using namespace std;

int main() {
    SeqList seqList{};
    initDefaultSeqList(seqList);
    printSeqList(seqList);
    cout << seqSearch(seqList, 1) << endl;
    return 0;
}
