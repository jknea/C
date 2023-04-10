#include <stdio.h>
#include <stdbool.h>

bool power_of_two(unsigned n) {
    if (n == 0) {
        return 0;
    }
    return (n & (n - 1)) == 0;  // since powers of two only have one set bit
}

int main() {
    int arr[] = {0, 1, 2, 3, 4};
    bool pow_of_two;
    for (int i = 0; i < 5; i++) {
        pow_of_two = power_of_two(i);
        (pow_of_two) ? printf("%d is a power of two\n", i) : printf("%d is not a power of two\n", i);
    }
    return 0;
}