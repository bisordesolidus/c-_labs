#include <iostream>

struct DynamicArray {
    int* data;
    int capacity;
    int size;

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    void insert_back(int value) {
        if (size == capacity) {
            resize(capacity + 1);
        }
        data[size++] = value;
    }

    void insert(int idx, int value) {
        if ((idx < 0) or (idx > size)) {
            std::cout << "Invalid index\n";
            return;
        }
        if (size == capacity) {
            resize(capacity +1);
        }
        for (int i = size; i > idx; i--) {
            data[i] = data[i - 1];
        }
        data[idx] = value;
        size++;
    }

    void remove(int idx) {
        if ((idx < 0) or (idx >= size)) {
            std::cout << "Invalid index\n";
            return;
        }
        for (int i = idx; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
};