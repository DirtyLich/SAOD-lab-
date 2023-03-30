#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void counting_sort(uint32_t arr[], uint32_t n) {
    uint32_t max = 0;
    for (uint32_t i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    uint32_t* count_arr = (uint32_t*) calloc(max+1, sizeof(uint32_t));
    for (uint32_t i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }

    uint32_t j = 0;
    for (uint32_t i = 0; i <= max; i++) {
        while (count_arr[i] > 0) {
            arr[j] = i;
            j++;
            count_arr[i]--;
        }
    }
    free(count_arr);
}

int main() {
    uint32_t n = 100000;
    uint32_t* arr = (uint32_t*) malloc(n * sizeof(uint32_t));

    // Заполнение массива случайными числами
    srand(time(NULL));
    for (uint32_t i = 0; i < n; i++) {
        arr[i] = rand() % 100001;
    }

    // Измерение времени работы сортировки
    clock_t start = clock();
    counting_sort(arr, n);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n", time_spent);

    // Проверка правильности сортировки (вывод отсортированного массива)

    free(arr);
    return 0;
}

