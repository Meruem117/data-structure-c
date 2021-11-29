#include <iostream>
#include "src/list.h"
#include "src/search.h"

using namespace std;

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 5;
    List list{};
    List list1{};

    setList(list, a, 10);
    printList(list);
    setList(list1, a, 9);
    printList(list1);

    cout << seqSearch(list, key) << endl;
    cout << seqSearchWithSentry(list1, key) << endl;
    cout << binSearch(list, key) << endl;

    return 0;
}
