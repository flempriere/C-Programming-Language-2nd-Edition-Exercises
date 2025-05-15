/**
 * @file ex3-6.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.6 from The C Programming Language, 2nd Edition.
 *
 * Write a function `itoa` that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if nessecary to make it wide enough.
 *
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
 * @brief Write a string representation of n in s to a minimum field width w.
 *
 * @param n integer to write.
 * @param s string to store representation of n.
 * @param w minimum width of the field.
 *
 * @warning s must be large enough to store the conversion.
 */
void itoa(int n, char s[], int w);

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
 * Given an input integer n, and width w compares the result of itoa(n,s, w) to
 * the expected output. Prints an error diagnostic if they disagree.
 *
 * @param n integer to convert
 * @param w minimum field width
 * @param expected expected result of itoa(n,s,w).
 *
 * @return TRUE if the results agree, else
 * @return FALSE
 */
enum truth test_itoa(int n, int w, char expected[]);

/**
 * @brief Computes the width of an unsigned int on this computer.
 *
 * @return int Bit width of unsigned.
 */
unsigned unsigned_width(void);

/**
 * @brief Test driver for itoa.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    // test normal
    if (!test_itoa(0, 0, "0")) { return EXIT_FAILURE; }
    if (!test_itoa(-0, 0, "0")) { return EXIT_FAILURE; }
    if (!test_itoa(1, 0, "1")) { return EXIT_FAILURE; }
    if (!test_itoa(-1, 0, "-1")) { return EXIT_FAILURE; }
    if (!test_itoa(9, 0, "9")) { return EXIT_FAILURE; }
    if (!test_itoa(-9, 0, "-9")) { return EXIT_FAILURE; }
    if (!test_itoa(12345, 0, "12345")) { return EXIT_FAILURE; }
    if (!test_itoa(-12345, 0, "-12345")) { return EXIT_FAILURE; }

    // test padded
    if (!test_itoa(0, 4, "   0")) { return EXIT_FAILURE; }
    if (!test_itoa(-0, 4, "   0")) { return EXIT_FAILURE; }
    if (!test_itoa(1, 4, "   1")) { return EXIT_FAILURE; }
    if (!test_itoa(-1, 4, "  -1")) { return EXIT_FAILURE; }
    if (!test_itoa(9, 4, "   9")) { return EXIT_FAILURE; }
    if (!test_itoa(-9, 4, "  -9")) { return EXIT_FAILURE; }
    if (!test_itoa(12345, 4, "12345")) { return EXIT_FAILURE; }
    if (!test_itoa(-12345, 4, "-12345")) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void itoa(int n, char s[], int w) {
    int sign = n;
    int i = 0;
    do { s[i++] = abs(n % 10) + '0'; } while ((n /= 10));
    if (sign < 0) { s[i++] = '-'; }
    while (i < w) { s[i++] = ' '; }
    s[i] = '\0';
    reverse(s);
}

int abs(int x) { return (x < 0) ? -x : x; }

void reverse(char s[]) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

enum truth test_itoa(int n, int w, char expected[]) {
    char intermediate[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) { intermediate[i] = 0; }

    itoa(n, intermediate, w);
    if (strcmp(intermediate, expected)) {
        printf("Error converting %d produced %s\n", n, intermediate);
        printf("Expected: %s\n", expected);
        return FALSE;
    }
    return TRUE;
}