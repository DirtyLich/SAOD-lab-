#include <stdio.h>    // для стандартного ввода-вывода
#include <stdlib.h>   // для функций выделения памяти, генерации псевдослучайных чисел и т.д.
#include <time.h>     // для работы со временем
#include <stdint.h>   // для использования фиксированных размеров целых чисел

#define MAX 100000    // максимальный размер массива

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
    uint32_t arr[MAX];  // объявляем массив с максимальным размером MAX
    clock_t start, end; // объявляем переменные для замера времени работы программы

    srand(time(NULL));  // инициализируем генератор псевдослучайных чисел текущим временем
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100001; // заполняем массив псевдослучайными числами из интервала [0,100000]
    }

    start = clock();  // запоминаем время начала работы алгоритма
    insertionSort(arr, MAX);  // вызываем функцию сортировки вставками
    end = clock();    // запоминаем время окончания работы алгоритма

    printf("Sorted array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);  // выводим отсортированный массив на экран
    }

    printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);  // выводим время работы программы
    return 0;
}
