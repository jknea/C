#include <stdio.h>
#include <math.h>

void unset_only_setbit(int* n) {
    if (*n & (*n - 1)) {
        printf("Invalid input\n");
    }
    return log2(*n) + 1;
}

int main() {
    int arr[] = {2, 7};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        unset_only_setbit(&arr[i]);
    }
    return 0;
}