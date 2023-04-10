#include <stdio.h>

void off_kth_bit(int* n, int k) {
    *n &= ~(1 << (k - 1));
}

int main() {
    int x = 7, bit = 3;
    printf("x is %d\n", x);
    off_kth_bit(&x, bit);  // 1-based numbering
    printf("after turning off bit %d, x is now %d\n", bit, x);
}