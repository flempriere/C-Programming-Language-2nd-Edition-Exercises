/**
 * @file fahrenheit_to_celsius.c
 * @author Felix Lempriere
 * @brief Prints a table of conversions from Fahrenheit to Celsius.
 * Uses an integer representation of the values.
 *
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints a Fahrenheit-Celsius Table for
 * fahr = 0, 20, ... 300.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int fahr, celsius;

    int lower = 0;      // lower limit of temperature scale
    int upper = 300;    // upper limit
    int step = 20;      // step size

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return EXIT_SUCCESS;
}
