#include <stdio.h>
#include <stdbool.h>

// macros to generate parity lookup table
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define FIND_PARITY P6(0), P6(1), P6(1), P6(0)

// macros to generate setbits lookup table
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)

unsigned int parity_lookup[256] = {FIND_PARITY};
unsigned int setbits_lookup[256] = {COUNT_BITS};

bool odd_parity(unsigned n) {
    bool odd_par = false;
    while (n) {
        odd_par = !odd_par;
        n &= (n - 1);
    }
    return odd_par;
}

bool lookupParity(int n) {
    // break 32-bit int into 16-bit chunks and take XOR
    n ^= (n >> 16);
    n ^= (n >> 8);
    return parity_lookup[n & 0xFF];
}

unsigned count_setbits(int n) {
    unsigned count = 0;
    while (n) {
        count++;
        n &= (n - 1);
    }
    return count;
}

unsigned lookupSetbits(int n) {
    return setbits_lookup[n & 0xFF] + setbits_lookup[(n >> 8) & 0xFF] + setbits_lookup[(n >> 16) & 0xFF] + setbits_lookup[(n >> 24) & 0xFF];
}

int main() {
    int arr[] = {2, 3, 4, 5, 6};
    int odd_par;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        odd_par = odd_parity(arr[i]);
        (odd_par) ? printf("parity of %d is odd\n", arr[i]) : printf("parity of %d is even\n", arr[i]);
        odd_par = lookupParity(arr[i]);
        (odd_par) ? printf("parity of %d is odd\n", arr[i]) : printf("parity of %d is even\n", arr[i]);    
    }
    printf("the number of set bits in %d is %d\n", 3, count_setbits(3));
    printf("the number of set bits in %d is %d\n", 3, lookupSetbits(3));
    printf("the number of set bits in %d is %d\n", -1, count_setbits(-1));
    printf("the number of set bits in %d is %d\n", -1, lookupSetbits(-1));
    return 0;
}