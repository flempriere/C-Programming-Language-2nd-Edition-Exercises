/**
 * @file ex1-5.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.5 from The C Programming Language, 2nd Edition.
 *
 * Modifies the Temperature conversion program to print the table in reverse
 * order, that is from 300 to 0 degrees.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
    return EXIT_SUCCESS;
}