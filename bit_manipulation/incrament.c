#include <stdio.h>

int main() {
    for (int i = -10; i < 10; i = -~i) {    // -~i = i + 1
        printf("i = %d\n", i);
    }
    return 0;
}