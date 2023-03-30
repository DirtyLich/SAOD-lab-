#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX 100000
#define RANGE 100001

void countingSort(uint32_t arr[], uint32_t sorted[], int n) {
    uint32_t count[RANGE] = {0}; // создаем массив для подсчета частоты вхождения каждого элемента в массиве
    int i;

    for (i = 0; i < n; i++) {
        count[arr[i]]++; // увеличиваем значение соответствующего элемента в массиве частот
    }

    for (i = 1; i < RANGE; i++) {
        count[i] += count[i - 1]; // суммируем частоты до текущего элемента
    }

    for (i = n - 1; i >= 0; i--) {
        sorted[count[arr[i]] - 1] = arr[i]; // помещаем каждый элемент на свою позицию в отсортированном массиве
        count[arr[i]]--; // уменьшаем значение соответствующего элемента в массиве частот
    }
}

int main() {
    uint32_t arr[MAX], sorted[MAX];
    clock_t start, end;

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % RANGE; // заполняем массив псевдослучайными числами из интервала [0,100000]
    }

    start = clock();
    countingSort(arr, sorted, MAX);
    end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", sorted[i]);
    }

    printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
