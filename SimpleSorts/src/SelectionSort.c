#include <stdio.h>

#define SIZE 10

void selectionSort(int arr[], int size) {
    int minIndex;
    int temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void appendSorted(int unsorted[], int sorted[], int size) {
    for (int i = 0; i < size; i++) {
        sorted[i] = unsorted[i];
    }
    selectionSort(sorted, size);
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