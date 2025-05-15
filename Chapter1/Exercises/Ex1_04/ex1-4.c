/**
 * @file ex1-4.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.4 from the C Programming Language, 2nd Edition.
 *
 * Print a table converting Celsius to Fahrenheit.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints a conversion table from Celsius to Fahrenheit.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    float lower = 0;
    float upper = 300;
    float step = 20;

    printf("Celsius Fahrenheit\n");
    float celsius = lower;
    while (celsius <= upper) {
        float fahr = (9.0 / 5.0) * celsius + 32;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return EXIT_SUCCESS;
}