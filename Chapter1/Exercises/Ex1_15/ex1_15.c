/**
 * @file ex1_15.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.15 from The C Programming Language, 2nd
 * Edition.
 *
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion.
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
 * @brief Converts Fahrenheit to Celsius
 *
 * @param fahrenheit
 * @return double
 */
double fahrenheit_to_celsius(double fahrenheit);

/**
 * @brief Prints a table converting fahrenheit to celsius for
 * fahr = LOWER to UPPER in steps of STEP.
 *
 * @return int
 */
int main(void) {
    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, fahrenheit_to_celsius(fahr));
    }
    return EXIT_SUCCESS;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}