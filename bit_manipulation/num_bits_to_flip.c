#include <stdio.h>

unsigned num_bits_to_flip(int a, int b) {
    int n = a ^ b;
    int count = 0;
    while (n) {
        n &= (n - 1);  // clear rightmost setbit
        count++;
    }
    return count;
}

int main() {
    int x = 10, y = 33;
    unsigned bits = num_bits_to_flip(x, y);
    printf("The number of bits to flip to turn %d into %d is %d\n", x, y, bits);
}