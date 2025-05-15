/**
 * @file itoa.c
 * @author Felix Lempriere
 * @brief Convert an integer to a string representation.
 *
 * Demonstrates the use of a do-while loop in converting an integer to a string.
 * @version 0.1
 * @date 2025-04-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief maximum line buffer size
 *
 */
#define MAX_SIZE 100

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
 * @brief Write a string representation of n into s
 *
 * @param n integer to write
 * @param s string to store representation of n
 *
 * @warning s must be large enough to store the conversion.
 */
void itoa(int n, char s[]);

/**
 * @brief reverses a string.
 *
 * Reverses the string stored in s. The reverse
 * is performed inplace.
 *
 * @param s buffer storing the string.
 */
void reverse(char s[]);

/**
 * @brief Tests the function itoa.
 *
 * Given an input integer n, compares the result of itoa(n) to the expected
 * output. Prints an error diagnostic if they disagree.
 *
 * @param n integer to convert
 * @param expected expected result of itoa(n, s).
 *
 * @return TRUE if the results agree, else
 * @return FALSE
 */
enum truth test_itoa(int n, char expected[]);

/**
 * @brief Test driver for itoa.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    if (!test_itoa(0, "0")) { return EXIT_FAILURE; }
    if (!test_itoa(-0, "0")) { return EXIT_FAILURE; }
    if (!test_itoa(1, "1")) { return EXIT_FAILURE; }
    if (!test_itoa(-1, "-1")) { return EXIT_FAILURE; }
    if (!test_itoa(9, "9")) { return EXIT_FAILURE; }
    if (!test_itoa(-9, "-9")) { return EXIT_FAILURE; }
    if (!test_itoa(12345, "12345")) { return EXIT_FAILURE; }
    if (!test_itoa(-12345, "-12345")) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void itoa(int n, char s[]) {
    int sign = n;
    if (sign < 0) {    // record sign, then work with positive n
        n = -n;
    }
    int i = 0;
    do { s[i++] = n % 10 + '0'; } while ((n /= 10));
    if (sign < 0) { s[i++] = '-'; }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

enum truth test_itoa(int n, char expected[]) {
    char intermediate[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) { intermediate[i] = 0; }

    itoa(n, intermediate);
    if (strcmp(intermediate, expected)) {
        printf("Error converting %d produced %s\n", n, intermediate);
        printf("Expected: %s\n", expected);
        return FALSE;
    }
    return TRUE;
}