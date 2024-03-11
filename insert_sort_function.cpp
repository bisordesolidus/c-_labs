#include "sort_function.h"


void insert_sort(int* mas, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = mas[i];
        j = i - 1;
        while (j >= 0 && mas[j] > key) {
            mas[j + 1] = mas[j];
            j = j - 1;
        }
        mas[j + 1] = key;
    }
}
