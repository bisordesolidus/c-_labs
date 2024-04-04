#include <iostream>

void heapify(int* mas, int n, int i) {
    /*создание двоичного дерева*/
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((left < n) and (mas[left] > mas[largest])) {
        largest = left;
    }
    if ((right < n) && (mas[right] > mas[largest])) {
        largest = right;
    }

    if (largest != i) {
        std::swap(mas[i], mas[largest]);
        heapify(mas, n, largest);
    }
}

void heapSort(int* mas, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(mas, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(mas[0], mas[i]);
        heapify(mas, i, 0);
    }
}
