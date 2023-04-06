#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX 100000

void quickSort(uint32_t arr[], int left, int right) {
    int i = left, j = right;
    uint32_t pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            uint32_t temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    uint32_t arr[MAX];
    clock_t start, end;

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100001; // заполняем массив псевдослучайными числами из интервала [0,100000]
    }

    start = clock();
    quickSort(arr, 0, MAX - 1);
    end = clock();

    printf("Sorted array:\n");
   

    printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
