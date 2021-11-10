#include <iostream>
#include "include/list.h"

int main() {
    SeqList seqList{};
    initSeqList(seqList);
    setSeqList(seqList);
    printSeqList(seqList);
    return 0;
}
