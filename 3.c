#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX 100000

void insertionSort(uint32_t arr[], int n) {
    int i, j;
    uint32_t key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // перемещаем элементы, которые больше ключевого, на одну позицию вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // помещаем ключевой элемент на свою позицию в отсортированной последовательности
    }
}

int main() {
    uint32_t arr[MAX];
    clock_t start, end;

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100001; // заполняем массив псевдослучайными числами из интервала [0,100000]
    }

    start = clock();
    insertionSort(arr, MAX);
    end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
