#include <stdio.h>

unsigned absolute(int n) {
    return (n + (n >> 31)) ^ (n >> 31);
}

int main() {
    for (int i = -5; i < 6; i++) {
        printf("%d\n", absolute(i));
    }
    return 0;
}