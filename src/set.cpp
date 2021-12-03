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

void unionSet(int S[], int root1, int root2) {
    if (root1 == root2) {
        return;
    }
    if (S[root2] > S[root1]) {
        S[root1] += S[root2];
        S[root2] = root1;
    } else {
        S[root2] += S[root1];
        S[root1] = root2;
    }
}
