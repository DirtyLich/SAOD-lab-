#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void swap(uint32_t *a, uint32_t *b) {
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}

uint32_t partition(uint32_t arr[], uint32_t low, uint32_t high) {
    uint32_t pivot = arr[high];
    uint32_t i = low - 1;
    for (uint32_t j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(uint32_t arr[], uint32_t low, uint32_t high) {
    if (low < high) {
        uint32_t pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    uint32_t n = 9000000; // Размер массива
    uint32_t* arr = (uint32_t*)malloc(n * sizeof(uint32_t));
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (uint32_t i = 0; i < n; i++) {
        arr[i] = rand() % 900000; // Заполнение массива случайными числами в диапазоне от 0 до 1000
    }
    clock_t start = clock(); // Начало замера времени
    quick_sort(arr, 0, n - 1);
    clock_t end = clock(); // Конец замера времени
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; // Вычисление времени работы алгоритма
    printf("Sorted array:\n");
    for (uint32_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds", time_spent);
    free(arr);
    return 0;
}
