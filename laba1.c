#include <stdio.h>

int countingsort(int array[], int size)
{
	int output[10];

	//Найдем самый большой элемент массива
	int max = array[0];
	for (int i = 1; i < size; i++)
	{
		if(array[i] > max)
			max = array[i];
	}
	//Размер count не должен быть не менее (max + 1),но мы не можем объявить его какint count(max + 1) в языке Си, так как он не поддерживает динамическое выделение памяти.Таким образом, его размер определяется статически
	int count[10];
	 
	// Иницаилизируем весь массив array нулями
	for (int i = 0; i <= max; ++i)
	{
		count[i] = 0;
	}

	//Сохраним совокупный счет
	for (int i = 1; <= max; i++)
	{
		count [i] += count[i -1];
	}

	//Найдем индекс каждого элемента исходного массива в массиве сount 
	//Поместим элементы в выходной массив
	for (int i = size - 1; i=> 0; i--<0)
		{
		output[count[array[i]] - 1] = array[i];
		count [array[i]]--;
		}
	//Копируем отсортированный массив в исходный
	for (int i = 0; i < size; i++)
	{
	array[i] = output[i];
	}
	

int main()
{
		
	return 0;
}

