/**
 * @file leap_year.c
 * @author Felix Lempriere
 * @brief Demonstrates the modulus operator to determine the leap years from
 * 1900 to 2100.
 *
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Starting year to calculate leap years from.
 *
 */
#define START_YEAR 1900

/**
 * @brief Final year to check for leap years.
 *
 */
#define STOP_YEAR 2100

/**
 * @brief Marks if the years the from START_YEAR through to STOP_YEAR
 * are leap years.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    for (int year = START_YEAR; year <= STOP_YEAR; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            printf("%d is a leap year\n", year);
        } else {
            printf("%d is not a leap year\n", year);
        }
    }

    return EXIT_SUCCESS;
}