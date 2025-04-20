/**
 * @file fahrenheit_to_celsius_v3.c
 * @author Felix Lempriere
 * @brief Version of the Fahrenheit to Celsius conversion program utilising
 * a for loop.
 *
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Print a table converting Fahrenheit to Celsius.
 *
 * @return EXIT_SUCCESS.
 */
int main(void) {
    for (int fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return EXIT_SUCCESS;
}