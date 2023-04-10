#include <stdio.h>

void upper_to_lower() {
    for (char c = 'A'; c <= 'Z'; c++) {
        char lower = c | ' ';
        printf("upper = %c, lower = %c\n", c, lower);
    }
}

void lower_to_upper() {
    for (char c = 'a'; c <= 'z'; c++) {
        char upper = c & '_';
        printf("lower = %c, upper = %c\n", c, upper);
    }
}

void invert_case() {
    for (char c = 'a'; c <= 'z'; c++) {
        char inv = c ^ ' ';
        printf("original = %c, new = %c\n", c, inv);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        char inv = c ^ ' ';
        printf("original = %c, new = %c\n", c, inv);
    }
}

int main() {
    upper_to_lower();
    lower_to_upper();
    invert_case();
    return 0;
}