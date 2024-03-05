#include "sort_function.h"

void choice_sort(int* mas, int size)
{
	int min = 0;
	int buf = 0;

	for (int i = 0; i < size; i++)
	{
		min = i; 
		for (int j = i + 1; j < size; j++)
			min = (mas[j] < mas[min]) ? j : min;
		if (i != min)
		{
			buf = mas[i];
			mas[i] = mas[min];
			mas[min] = buf;
		}
	}
}