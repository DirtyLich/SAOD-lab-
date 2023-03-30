#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX 1000000
#define RANGE 1000001

void countingSort(uint32_t arr[], uint32_t sorted[], int n) {
uint32_t *count = calloc(RANGE, sizeof(uint32_t)); // выделяем память для массива для подсчета частоты вхождения каждого элемента в массиве
int i;

for (i = 0; i < n; i++) {
count[arr[i]]++; // увеличиваем значение соответствующего элемента в массиве частот
}

for (i = 1; i < RANGE; i++) {
count[i] += count[i - 1]; // суммируем частоты до текущего элемента
}

int *used = calloc(RANGE, sizeof(int)); // массив, указывающий, было ли число уже учтено при подсчете частот

for (i = n - 1; i >= 0; i--) {
if (!used[arr[i]]) {
sorted[count[arr[i]] - 1] = arr[i]; // помещаем каждый элемент на свою позицию в отсортированном массиве
used[arr[i]] = 1; // помечаем число, как учтенное
}
count[arr[i]]--; // уменьшаем значение соответствующего элемента в массиве частот
}
free(count); // освобождаем память, выделенную для массива count
free(used); // освобождаем память, выделенную для массива used
}

int main() {
uint32_t *arr = malloc(MAX * sizeof(uint32_t));
uint32_t *sorted = malloc(MAX * sizeof(uint32_t));
clock_t start, end;

srand(time(NULL));
for (int i = 0; i < MAX; i++) {
arr[i] = rand() % RANGE; // заполняем массив псевдослучайными числами из интервала [0,100000]
}

start = clock();
countingSort(arr, sorted, MAX);
end = clock();

printf("Sorted array:\n");

printf("\n\nExecution time: %f seconds", (double)(end - start) / CLOCKS_PER_SEC);

free(arr);
return 0;
}
