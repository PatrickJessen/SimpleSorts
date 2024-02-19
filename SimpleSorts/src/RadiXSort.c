#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int size, int exp) {
    int* output = (int*)malloc(size * sizeof(int));
    int i, count[10] = { 0 };

    for (i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        arr[i] = output[i];

    free(output);
}

void radixSort(int arr[], int size) {
    int max = getMax(arr, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, size, exp);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int unsorted[SIZE] = { 170, 45, 75, 90, 802, 24, 2, 66, 150, 0 };
    int sorted[SIZE];

    radixSort(unsorted, SIZE);
    printArray(unsorted, SIZE);

    return 0;
}
