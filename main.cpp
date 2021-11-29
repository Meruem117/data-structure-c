#include <iostream>
#include "src/list.h"
#include "src/search.h"
#include "src/sort.h"

using namespace std;

void testSearch() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = 6;

    cout << seqSearch(a, 10, key) << endl;
    cout << binSearch(a, 10, key) << endl;
    cout << seqSearchWithSentry(a, 9, key) << endl;
}

void testSort() {
    int a[10] = {2, 1, 3, 4, 5, 0, 6, 8, 9, 7};
    insertSort(a, 10);
}

int main() {
    testSearch();
    testSort();
    return 0;
}
