/**
 * @file fahrenheit_to_celsius_v2.c
 * @author Felix Lempriere
 * @brief An improved version of fahrenheit_to_celsius which uses float
 * to improve the accuracy and format specifiers to format the output.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Print Fahrenheit to Celsius table for
 * fahr = 0, 20, ..., 300 using a floating point
 * representation.
 *
 * @return EXIT_SUCCESS.
 */
int main(void) {
    float lower = 0;
    float upper = 300;
    float step = 20;

    float fahr = lower;
    while (fahr <= upper) {
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return EXIT_SUCCESS;
}