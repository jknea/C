#include <stdio.h>
#include <stdbool.h>

bool check_kth_bit(int n, int k) {
    return (n & (1 << (k - 1))) != 0;  // returns 1 if bit is set
}

int main() {
    int x = 7;
    bool set;
    for (int i = 1; i < 6; i++) {
        set = check_kth_bit(x, i);
        (set) ? printf("bit %d of %d is set\n", i, x) : printf("bit %d of %d is not set\n", i, x);
    }
    return 0;
}