//
// Created by Meruem on 2021/12/3.
//

#include "set.h"

void initSet(int S[], int size) {
    for (int i = 0; i < size; i++) {
        S[i] = -1;
    }
}

int findSet(int S[], int x) {
    int root = x;
    while (S[root] >= 0) {
        root = S[root];
    }
    while (x != root) {
        int t = S[x];
        S[x] = root;
        x = t;
    }
    return root;
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

int componentCount(int G[5][5]) {
    int S[5];
    initSet(S, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (G[i][j] > 0) {
                int iRoot = findSet(S, i);
                int jRoot = findSet(S, j);
                if (iRoot != jRoot) {
                    unionSet(S, iRoot, jRoot);
                }
            }
        }
    }
    int count = 0;
    for (int i: S) {
        if (i < 0) {
            count++;
        }
    }
    return count;
}

int hasAcyclic(int G[5][5]) {
    int S[5];
    initSet(S, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (G[i][j] > 0) {
                int iRoot = findSet(S, i);
                int jRoot = findSet(S, j);
                if (iRoot != jRoot) {
                    unionSet(S, iRoot, jRoot);
                } else {
                    return 1;
                }
            }
        }
    }
    return 0;
}
