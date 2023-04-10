#include <stdio.h>

int main() {
    for (int i = 0; i < 20; i++) {
        (i & 1) ? printf("%d is odd\n", i) : printf("%d is even\n", i);
    }
    return 0;
}