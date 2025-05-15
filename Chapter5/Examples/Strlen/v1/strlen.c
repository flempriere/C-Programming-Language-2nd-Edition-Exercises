/**
 * @file strlen.c
 * @author Felix Lempriere
 * @brief Implementation of strlen.
 *
 * Demonstrates array to pointer decay.
 * @version 0.1
 * @date 2025-05-09
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
 * @brief Tests strlen by reading in a string in, and running strlen,
 * the result is compared to the expected result, expected. An error diagnostic
 * is printed if the test is failed.
 *
 * @param in string to test
 * @param expected expected result
 * @return TRUE if the test is passed, else
 * @return FALSE.
 */
enum truth test_strlen(char in[], int expected);

/**
 * @brief Calculate the length of the string.
 *
 * @param s
 * @return int length of the string
 */
int my_strlen(char* s);

/**
 * @brief Test driver for string length
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    if (!test_strlen("", 0)) { return EXIT_FAILURE; }
    if (!test_strlen("a", 1)) { return EXIT_FAILURE; }
    if (!test_strlen("abc", 3)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int my_strlen(char* s) {
    int n;
    for (n = 0; *s != '\0'; s++) { n++; }
    return n;
}

enum truth test_strlen(char in[], int expected) {
    int res = my_strlen(in);
    if (res != expected) {
        printf("Test failed\n");
        printf("input: %s, result: %d, expected: %d\n", in, res, expected);
        return FALSE;
    }
    return TRUE;
}