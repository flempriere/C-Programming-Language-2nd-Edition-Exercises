/**
 * @file atoi.c
 * @author Felix Lempriere
 * @brief Simple implementation of atoi, converting a string to an integer.
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
 * @brief Converts the string s to an integer
 *
 * @param s string to convert.
 * @return integer result of converting s
 */
int my_atoi(char s[]);

/**
 * @brief tests my_atoi by converting the string s
 * and comparing it to expected. An error diagnostic
 * is printed if they disagree.
 *
 * @param s input string
 * @param expected expected out.
 * @return TRUE if my_atoi(s) == expected, else
 * @return FALSE
 */
enum truth test_my_atoi(char s[], int expected);

/**
 * @brief Test driver, calls it will single digit and multidigit numbers.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    if (!test_my_atoi("0", 0)) { return EXIT_FAILURE; }
    if (!test_my_atoi("5", 5)) { return EXIT_FAILURE; }
    if (!test_my_atoi("9", 9)) { return EXIT_FAILURE; }
    if (!test_my_atoi("12345", 12345)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int my_atoi(char s[]) {
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

enum truth test_my_atoi(char s[], int expected) {
    int res = my_atoi(s);
    if (res != expected) {
        printf("Error: failed test on converting %s\n", s);
        printf("Error: result: %d, expected: %d\n", res, expected);
        return FALSE;
    }
    return TRUE;
}