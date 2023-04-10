#include <stdio.h>
#include <math.h>

int nextPowOf2_1(int n) {
    n--; // handles power of two case
    while (n & (n - 1)) {
        n &= (n - 1);
    }
    return n << 1;
}

int nextPowOf2_2(int n) {
    n--; // handles power of two case
    int k = 2;
    while (n >>= 1) {   // divide n by 2 until it becomes 0
        k = k << 1; // double k
    }
    return k;
}

int nextPowOf2_3(int n) {
    n--; // handles power of two case
    int l = log2(n);
    return 1 << l + 1;
}

int nextPowOf2_4(int n) {
    n--; // handles power of two case
    // set all bits after the last setbit
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    return n + 1;    
}

int prevPowOf2_1(int n) {
    while (n & (n - 1)) {
        n &= (n - 1);
    }
    return n;
}

int prevPowOf2_2(int n) {
    int k = 1;
    while (n >>= 1) {   // divide n by 2 until it becomes 0
        k = k << 1; // double k
    }
    return k;
}

int prevPowOf2_3(int n) {
    int l = log2(n);
    return 1 << l;
}

int prevPowOf2_4(int n) {
    // set all bits after the last setbit
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    return n - (n >> 1);    
}

int main() {
    int arr[] = {4, 11};
    for (int i = 0; i < 2; i++) {
        printf("The next power of two of %d is %d\n", arr[i], nextPowOf2_1(arr[i]));
        printf("The next power of two of %d is %d\n", arr[i], nextPowOf2_2(arr[i]));
        printf("The next power of two of %d is %d\n", arr[i], nextPowOf2_3(arr[i]));
        printf("The next power of two of %d is %d\n", arr[i], nextPowOf2_4(arr[i]));
        printf("The prev power of two of %d is %d\n", arr[i], prevPowOf2_1(arr[i]));
        printf("The prev power of two of %d is %d\n", arr[i], prevPowOf2_2(arr[i]));
        printf("The prev power of two of %d is %d\n", arr[i], prevPowOf2_3(arr[i]));
        printf("The prev power of two of %d is %d\n", arr[i], prevPowOf2_4(arr[i]));
    }
    return 0;
}