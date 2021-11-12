#include <iostream>
#include "include/list.h"
#include "include/search.h"

using namespace std;

int main() {
    SeqList seqList{};
    initDefaultSeqList(seqList);
    printSeqList(seqList);
    cout << binSearch(seqList, 11) << endl;
    return 0;
}
