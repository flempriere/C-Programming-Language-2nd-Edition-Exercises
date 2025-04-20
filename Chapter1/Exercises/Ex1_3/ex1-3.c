/**
 * @file ex1-3.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.3 from The C Programming Language, 2nd Edition.
 *
 * Modify the temperature conversion program to print a heading above the table.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float lower = 0;
    float upper = 300;
    float step = 20;

    printf("Fahr Celsius\n");
    float fahr = lower;
    while (fahr <= upper) {
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f %7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return EXIT_SUCCESS;
}