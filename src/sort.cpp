//
// Created by Meruem on 2021/11/29.
//

#include "sort.h"
#include "utils.h"

void insertSort(int a[], int len) {
    int i, j, tmp;
    for (i = 1; i < len; i++) {
        if (a[i] < a[i - 1]) {
            tmp = a[i];
            for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = tmp;
        }
    }
    printArray(a, len, false);
}

void shellSort(int a[], int len) {
    int d, i, j;
    for (d = len / 2; d >= 1; d /= 2) {
        for (i = d + 1; i <= len; i++) {
            if (a[i] < a[i - d]) {
                a[0] = a[i];
                for (j = i - d; j > 0 && a[0] < a[j]; j -= d) {
                    a[j + d] = a[j];
                }
                a[j + d] = a[0];
            }
        }
    }
    printArray(a, len, true);
}

void bubbleSort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        bool flag = false;
        for (int j = len - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
    printArray(a, len, false);
}

int partition(int a[], int low, int high) {
    int p = a[low];
    while (low < high) {
        while (low < high && a[high] >= p) high--;
        a[low] = a[high];
        while (low < high && a[low] <= p) low++;
        a[high] = a[low];
    }
    a[low] = p;
    return low;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void selectSort(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(a[i], a[min]);
        }
    }
    printArray(a, len, false);
}

void headAdjust(int a[], int k, int len) {
    a[0] = a[k];
    for (int i = k * 2; i <= len; i *= 2) {
        if (i < len && a[i] < a[i + 1]) {
            i++;
        }
        if (a[0] >= a[i]) {
            break;
        } else {
            a[k] = a[i];
            k = i;
        }
    }
    a[k] = a[0];
}

void buildMaxHeap(int a[], int len) {
    for (int i = len / 2; i > 0; i--) {
        headAdjust(a, i, len);
    }
}

void heapSort(int a[], int len) {
    buildMaxHeap(a, len);
    for (int i = len; i > 1; i--) {
        swap(a[i], a[1]);
        headAdjust(a, 1, i - 1);
    }
    printArray(a, len, true);
}

void merge(int a[], int low, int mid, int high, int b[]) {
    int i, j, k;
    for (k = low; k <= high; k++) {
        b[k] = a[k];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (b[i] <= b[j]) {
            a[k] = b[i++];
        } else {
            a[k] = b[j++];
        }
    }
    while (i <= mid) a[k++] = b[i++];
    while (j <= high) a[k++] = b[j++];
}

void mergeSort(int a[], int low, int high, int len) {
    int *b = (int *) malloc(len * sizeof(int));
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid, len);
        mergeSort(a, mid + 1, high, len);
        merge(a, low, mid, high, b);
    }
}
