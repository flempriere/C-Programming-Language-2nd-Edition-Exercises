/**
 * @file itoa.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 4.12 from The C Programming Language, 2nd
 * Edition.
 *
 * Adopt the ideas of printd to write a recursive version of itoa, that is
 * convert an integer into a string by calling a recursive routine.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

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
 * @brief Write a string representation of n in s
 *
 * @param n integer to write
 * @param s string to store representation of n
 *
 * @warning s must be large enough to store the conversion.
 */
void itoa(int n, char s[]);

/**
 * @brief Recursive subroutine for itoa
 *
 * @param n integer to convert
 * @param s string to store conversion in
 * @param i current index in the string.
 * @return int next free index in the string.
 */
int itoa_r(int n, char s[], int i);

/**
 * @brief Returns the absolute value of an integer n.
 *
 * @param n
 * @return -n if n < 0 else,
 * @return n
 *
 * @warning Will overflow on INT_MIN.
 */
int abs(int n);

/**
 * @brief Test two strings for equality
 *
 * @param s
 * @param t
 * @return TRUE if strings equal, else,
 * @return FALSE
 */
enum truth my_streq(char s[], char t[]);

/**
 * @brief Tests the function itoa.
 *
 * Given an input integer n, compares the result of itoa(n) to the expected
 * output. Prints an error diagnostic if they disagree.
 *
 * @param n integer to convert
 * @param expected expected result of itoa(n, s).
 * @return TRUE if the results agree, else
 * @return FALSE
 *
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
    int i = 0;
    if (n < 0) { s[i++] = '-'; }
    s[itoa_r(n, s, i)] = '\0';
}

int itoa_r(int n, char s[], int i) {
    if (n / 10) { i = itoa_r(n / 10, s, i); }
    s[i++] = abs(n % 10) + '0';
    return i;
}

int abs(int x) { return (x < 0) ? -x : x; }

enum truth my_streq(char s[], char t[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != t[i]) { return FALSE; }
    }
    return TRUE;
}

enum truth test_itoa(int n, char expected[]) {
    char intermediate[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) { intermediate[i] = 0; }

    itoa(n, intermediate);
    if (!my_streq(intermediate, expected)) {
        printf("Error converting %d produced %s\n", n, intermediate);
        printf("Expected: %s\n", expected);
        return FALSE;
    }
    return TRUE;
}