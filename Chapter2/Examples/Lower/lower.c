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
 * @brief enum storing false and true values
 *
 * FALSE = 0;
 * TRUE = 1
 */
enum truth {
    FALSE,
    TRUE
};

/**
 * @brief Converts the character c to a lower case c.
 *
 * @param c character to convert
 *
 * @warning This function only works for ASCII implementations.
 *
 * @return int character converted to lower case or unchanged
 * if it is not an upper case character.
 */
int lower(int c);

/**
 * @brief Tests the function lower, by applying it to c and
 * comparing it to the value expected. Prints an error diagnostic
 * if the test fails.
 *
 * @param c value to apply lower to.
 * @param expected expected result of lower(c)
 *
 * @return TRUE if lower(c) == expected, else
 * @return FALSE
 */
enum truth test_lower(int c, int expected);

/**
 * @brief Test driver for lower case conversion
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    if (!test_lower('a', 'a')) { return EXIT_FAILURE; }
    if (!test_lower('A', 'a')) { return EXIT_FAILURE; }
    if (!test_lower(' ', ' ')) { return EXIT_FAILURE; }
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

enum truth test_lower(int c, int expected) {
    int res = lower(c);
    if (res != expected) {
        printf("Error: c : %c, expected: %c, result: %c\n", c, expected, res);
        return FALSE;
    }
    return TRUE;
}