#include "sort_function.h"

void quick_sort(int* mas, int size) {

    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];
    while (i <= j){
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
    } 

    if (j > 0) {
        quick_sort(mas, j + 1);
    }
    if (i < size) {
        quick_sort(&mas[i], size - i);
    }
}