#include <stdio.h>

#define SIZE 10

void insertionSort(int arr[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void appendSorted(int unsorted[], int sorted[], int size) {
    for (int i = 0; i < size; i++) {
        sorted[i] = unsorted[i];
    }
    insertionSort(sorted, size);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int unsorted[SIZE] = { 3, 7, 9, 2, 9, 5, 9, 9, 8, 6 };
    int sorted[SIZE] = { 0 };

    appendSorted(unsorted, sorted, SIZE);
    printArray(sorted, SIZE);

    return 0;
}
