//
// Created by Meruem on 2021/12/3.
//

#include "set.h"

void initSet(int S[]) {
    for (int i = 0; i < SIZE; i++) {
        S[i] = -1;
    }
}

int findSet(int S[], int x) {
    while (S[x] >= 0) {
        x = S[x];
    }
    return x;
}

void unionSet(int S[], int roo1, int root2) {
    if (roo1 == root2) {
        return;
    }
    S[root2] = roo1;
}
