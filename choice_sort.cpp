#include "sort_function.h"

void main(int* a, int N)
{

	int min = 0;
	int buf = 0;

	for (int i = 0; i < N; i++)
	{
		min = i; 
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
}