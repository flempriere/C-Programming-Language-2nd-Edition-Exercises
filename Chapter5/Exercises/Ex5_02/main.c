/**
 * @file main.c
 * @author Felix Lempriere
 * @brief Driver for getfloat.c. Reads floats from the standard input. Solution
 * to Exercise 5.2 from The C Programming Language, 2nd Edition.
 *
 * Write `getfloat`, the floating-point analog of `getint`. What type does
 * `getfloat` return as its function value.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "getfloat.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Driver for getint.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    double array[SIZE];
    int n;
    int state;
    printf("Enter doubles seperated by whitespace\n");
    for (n = 0; n < SIZE && (state = getfloat(&array[n])) != EOF; n++);

    for (int j = 0; j < n; j++) printf("[%g]", array[j]);
    printf("\n");
    return EXIT_SUCCESS;
}