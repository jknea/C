#include <stdio.h>
#include <stdbool.h>

int main() {
    int a[3][2] = {{2,3},{-3,4},{-4,-5}};
    int x, y;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        x = a[i][0], y = a[i][1];
        bool opp_signs = (x ^ y) < 0;
        (opp_signs) ? printf("%d and %d have opposite signs\n", x, y) : printf("%d and %d have the same sign\n", x, y);
    }
    return 0;
}