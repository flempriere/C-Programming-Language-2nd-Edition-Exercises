/**
 * @file fahrenheit_to_celsius_v4.c
 * @author Felix Lempriere
 * @brief Version of fahrenheit_to_celsius replacing magic constant
 * values with #define constants.
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
 * @brief Lower limit of temperature range
 *
 * @see LOWER, @see STEP
 */
#define LOWER 0

/**
 * @brief Upper limit of temperature range
 *
 * @see LOWER, @see STEP
 */
#define UPPER 300

/**
 * @brief Step size between table entries.
 *
 * @see LOWER, @see UPPER
 */
#define STEP 20

/**
 * @brief Prints a table converting Fahrenheit to Celsius for
 * fahr from 0 to 300.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
    return EXIT_SUCCESS;
}