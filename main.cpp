#include <stdio.h>
#include <stdlib.h>
#include "sort_function.h"

int main()
{
    int a[1024];
    int b[1024];
    int c[1024];
    int d[1024];
    int e[1024];

    for (int i = 0; i < 8; i++) {
        a[i] = rand() % 20 - 10;
        b[i] = rand() % 20 - 10;
        c[i] = rand() % 20 - 10;
        d[i] = rand() % 20 - 10;
        e[i] = rand() % 20 - 10;
    }
    for (int i = 0; i < 8; i++)
        printf("%d ", a[i]);
    printf("\n");

    quick_sort(a, 1024);
    choice_sort(b, 1024);
    buble_sort(c, 1024);
    insert_sort(d, 1024);
    merge_sort(e, 1024);

    for (int i = 0; i < 8; i++)
        printf("%d ", a[i]);
    return 0;
}