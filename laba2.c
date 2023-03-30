
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int n = 9000000; // Размер массива
    int* arr = (int*)malloc(n * sizeof(int));
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 900000; // Заполнение массива случайными числами в диапазоне от 0 до 1000
    }
    clock_t start = clock(); // Начало замера времени
    quick_sort(arr, 0, n - 1);
    clock_t end = clock(); // Конец замера времени
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; // Вычисление времени работы алгоритма
    printf("Sorted array:\n");
    printf("\nTime taken: %f seconds", time_spent);
    free(arr);
    return 0;
}
    