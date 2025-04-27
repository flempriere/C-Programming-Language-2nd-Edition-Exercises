/**
 * @file strlen.c
 * @author Felix Lempriere
 * @brief Example implementation of strlen.
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
 * @brief Calculates the length of a string s.
 *
 * @param s
 * @return EXIT_SUCCESS
 */
int my_strlen(char s[]);

/**
 * @brief Tests my_strlen by comparing the result of my_strlen(s)
 * to expected. An error diagnostic is printed if the test fails.
 *
 * @param s input string
 * @param expected expected length
 * @return TRUE if my_strlen(s) == expected, else
 * @return FALSE.
 */
enum truth test_my_strlen(char s[], int expected);

/**
 * @brief Test driver for strlen.
 *
 * Tests the following
 * - empty string
 * - single character string
 * - multicharacter string
 *
 * @return EXIT_SUCCESS if all tests passed successfully, else
 * @return EXIT_FAILURE
 */
int main(void) {
    char empty[] = "";
    char single[] = "a";
    char multichar[] = "ab";

    if (my_strlen(empty) != 0) {
        printf("Test failed on empty string\n");
        return EXIT_FAILURE;
    }
    if (my_strlen(single) != 1) {
        printf("Test failed on single character string\n");
        return EXIT_FAILURE;
    }
    if (my_strlen(multichar) != 2) {
        printf("Test failed on multicharacter string\n");
        return EXIT_FAILURE;
    }
    printf("All tests passed\n");
    return EXIT_SUCCESS;
}

int my_strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') { ++i; }
    return i;
}

enum truth test_my_strlen(char s[], int expected) {
    int res = my_strlen(s);
    if (res != expected) {
        printf("Error: incorrect length for string %s\n", s);
        printf("Calculated length: %d, expected: %d\n", res, expected);
        return FALSE;
    }
    return TRUE;
}