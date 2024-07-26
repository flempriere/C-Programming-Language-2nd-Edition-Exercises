#include <stdio.h>
#include "swap.h"


int main(void) {
    printf("===Testing Swap ====\n"); 

    printf("Testing for int\n");
    int x = 0;
    int y = 1;
    printf("x, y: %d, %d\n", x, y);
    swap(int, x, y);
    printf("Swapped x, y: %d, %d\n", x,y);

    printf("Testing for a double\n");
    double s = 1.0e-3;
    double t = 1.0e+1;
    printf("s, t: %g, %g\n", s, t);
    swap(double, s, t);
    printf("Swapped s, t: %g, %g\n", s, t);

    return 0;
}