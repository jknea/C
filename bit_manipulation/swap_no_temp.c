#include <stdio.h>

void swap(int* x, int* y) {
    if (*x != *y) {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

int main() {
    int x = 10, y = 3;
    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}