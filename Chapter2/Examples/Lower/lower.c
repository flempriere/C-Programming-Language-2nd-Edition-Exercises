/**
 * @file lower.c
 * @author Felix Lempriere
 * @brief Convert a character c to lower case.
 *
 * @warning This version only works for ASCII encoded characters. 
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Converts the character c to a lower case c.
 *
 * @param c character to convert
 *
 * @warning This function only works for ASCII implementations.
 *
 * @return int character converted to lower case or unchanged.
 */
int lower(int c);

/**
 * @brief Test driver for lower case conversion
 *
 */
int main(void) {
    char c = 'a';
    int res = lower(c);
    if (res != c) {
        printf("Error: already lowercase character %c converted to %c\n", c, c);
        return EXIT_FAILURE;
    }
    c = 'A';
    if ((res = lower(c)) != 'a') {
        printf("Error: failed to convert uppercase character %c, result: %c", c,
               res);
        return EXIT_FAILURE;
    }
    c = ' ';
    if ((res = lower(c)) != c) {
        printf(
            "Error: incorrectly converted nonalphabetic character %c to %c\n",
            c, res);
        return EXIT_FAILURE;
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    } else {
        return c;
    }
}