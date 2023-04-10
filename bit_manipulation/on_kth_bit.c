#include <stdio.h>

void on_kth_bit(int* n, int k) {
    *n |= (1 << (k - 1));
}

int main() {
    int x = 3, bit = 3;
    printf("x is %d\n", x);
    on_kth_bit(&x, bit);  // 1-based numbering
    printf("after turning on bit %d, x is now %d\n", bit, x);
    return 0;
}