/**
 * @file power_v2.c
 * @author Felix Lempriere
 * @brief Modification of power.c to use the parameters rather than
 * local variables.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Computes the exponentiation of m raised to the n-th power.
 *
 * @param m base of the exponential
 * @param n power of the exponential
 * @return int m^n.
 */
int power(int m, int n);

/**
 * @brief Test driver for power(m,n)
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    printf("i: 2^i (-10)^i\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %3d %5d\n", i, power(2, i), power(-10, i));
    }
    return EXIT_SUCCESS;
}

int power(int m, int n) {
    int p;
    for (int p = 1; n > 0; --n) { p = p * m; }
    return p;
}