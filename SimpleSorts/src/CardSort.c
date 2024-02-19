#include <stdio.h>

// static const defines
#define ROWS 8
#define COLS 4

void sortCards(int arr[ROWS][COLS], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j / COLS][j % COLS] > arr[(j + 1) / COLS][(j + 1) % COLS]) {
                temp = arr[j / COLS][j % COLS];
                arr[j / COLS][j % COLS] = arr[(j + 1) / COLS][(j + 1) % COLS];
                arr[(j + 1) / COLS][(j + 1) % COLS] = temp;
            }
        }
    }
}

//void print(int arr[ROWS][COLS]) {
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}

//int main() {
//    int arr[ROWS][COLS] = { {408, 406, 423, 239},
//                           {486, 542, 211, 108},
//                           {659, 628, 471, 572},
//                           {446, 593, 629, 652},
//                           {607, 527, 265, 566},
//                           {582, 508, 589, 443},
//                           {565, 586, 649, 140},
//                           {293, 536, 270, 639} };
//
//    printf("Original array:\n");
//    print(arr);
//
//    sortCards(arr, ROWS * COLS);
//
//    printf("\nSorted array:\n");
//    print(arr);
//
//    return 0;
//}