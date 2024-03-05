#include "sort_function.h"
#include <iostream>

using namespace std;

void buble_sort(int* mas, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 9; j++) {
            if (mas[j] > mas[j + 1]) {
                int b = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = b;
            }
        }
    }
}

