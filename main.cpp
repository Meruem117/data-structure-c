#include <iostream>
#include "src/list.h"
#include "src/search.h"

using namespace std;

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    List list{};
    List listWithHead{};

    initList(list);
    setList(list, a, 10);
    printList(list, false);
    initList(listWithHead);
    setList(listWithHead, a, 9);
    printList(listWithHead, true);

    cout << seqSearch(list, key) << endl;
    cout << seqSearchWithSentry(listWithHead, key) << endl;
    cout << binSearch(list, key) << endl;

    return 0;
}
