/**
 * @file ex4-14.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 4.14 from The C Programming Language, 2nd
 * Edition.
 *
 * Define a macro `swap(t, x, y)` that interchanges two arguments of type `t`.
 * (Block structure will help.)
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Swap macro
 *
 * @param t type to swap
 * @param x first value to swap
 * @param y second value to swap
 */
#define swap(t, x, y) \
    do {              \
        t swap = x;   \
        x = y;        \
        y = swap;     \
    } while (0)

int main(void) {
    printf("===Testing Swap ====\n");

    printf("Testing for int\n");
    int x = 0;
    int y = 1;
    swap(int, x, y);
    if (x != 1 || y != 0) {
        printf("Test failed!\nResult: %d, %d\n, Expected: 1, 0\n", x, y);
        return EXIT_FAILURE;
    }
    printf("Testing for a double\n");
    double s = 1.0e-3;
    double t = 1.0e+1;
    swap(double, s, t);
    if (s != 1.0e+1 || t != 1.0e-3) {
        printf("Test failed!\nResult: %g, %g\n, Expected: 10.0, 0.001\n", s, t);
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}