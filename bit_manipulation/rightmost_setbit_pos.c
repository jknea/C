#include <stdio.h>
#include <math.h>

int rightmost_setbit_pos(int n) {
    if (n & 1) {
        return 1;
    }
    // option 1
    /*
    int pos = 0;
    while (n) {
        n >>= 1;
        pos++
    }
    return pos;
    */
    // option 2
    /*
    n ^= (n & (n - 1));
    return log2(n) + 1;
    */
    // option 3
    return log2(n & -n) + 1;
}

int main() {
    int x = 8;
    int pos = rightmost_setbit_pos(x);
    printf("The rightmost setbit of %d is at position %d\n", x, pos);
    return 0;
}