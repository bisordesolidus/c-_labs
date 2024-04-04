#include <stdio.h>
#include <stdlib.h>
#include "sort_function.h"

void merge_sort(int* mas, int size)
{
    int mid = size / 2;
    if (size % 2 == 1)
        mid++;
    int h = 1; 
    int* c = (int*)malloc(size * sizeof(int));
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;  
        int j = mid; 
        int k = 0;   
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            { 
                if (mas[i] < mas[j])
                {
                    c[k] = mas[i];
                    i++; k++;
                }
                else {
                    c[k] = mas[j];
                    j++; k++;
                }
            }
            while (i < step)
            { 
                c[k] = mas[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < size))
            { 
                c[k] = mas[j];
                j++; k++;
            }
            step = step + h; 
        }
        h = h * 2;
        for (i = 0; i < size; i++)
            mas[i] = c[i];
    }
}
