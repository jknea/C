#include <stdio.h>

void toggle_kth_bit(int* n, int k) {
    *n ^= (1 << (k - 1));
}

int main() {
    int x = 8, bit = 4;
    printf("x is %d\n", x);
    toggle_kth_bit(&x, bit);
    printf("after toggling bit %d, x is now %d\n", bit, x);
}