#include <stdio.h> //подключаем библиотеку ввода/вывода данных.
#include <stdlib.h> //подключаем библиотеку стандартных функций, таких как malloc и free.
#include <time.h> //подключаем библиотеку для работы с временем.

#include <stdint.h> //подключаем библиотеку для работы с целочисленными типами данных фиксированной длины.

#define MAX 100000
//объявляем функцию быстрой сортировки с тремя параметрами: массивом, левой и правой границами подмассива.
void quickSort(uint32_t arr[], int left, int right) {
    int i = left, j = right;
    uint32_t pivot = arr[(left + right) / 2]; // выбираем опорный элемент - средний элемент массива

    while (i <= j) {
        while (arr[i] < pivot) i++; // ищем элемент, больший или равный опорному, слева
        while (arr[j] > pivot) j--; // ищем элемент, меньший или равный опорному, справа
        if (i <= j) { // если найдены элементы, не находящиеся на своих местах, меняем их местами
            uint32_t temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j); // рекурсивно сортируем левую часть массива
    if (i < right) quickSort(arr, i, right); // рекурсивно сортируем правую часть массива
}

int main() {
    uint32_t arr[MAX];
    clock_t start, end;

    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100001; // заполняем массив псевдослучайными числами из интервала [0,100000]
    }

    start = clock();
    quickSort(arr, 0, MAX - 1); // вызываем функцию быстрой сортировки
    end = clock();

    printf("Sorted array:\n");
   
    // Вывод отсортированного массива
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC); // выводим время выполнения программы

    return 0;
}
