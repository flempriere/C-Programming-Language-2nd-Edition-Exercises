/**
 * @file ex3-4.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.4 from The C Programming Language, 2nd Edition
 *
 * In a two's complement number representation, our version of `itoa` does not
 * handle the largest negative number, that is, the value of `n` equal to
 * -(2^(n-1)) where n is the wordsize of int. Explain why not. Modify it to
 * print that value correctly regardless of the machine on which it runs.
 *
 * @remark Why? In two's complement the negative numbers are 1[000...000] ...
 * 1[1111...11], while the postive numbers have representations 0[000...000] ...
 * 0[1111...11]. But one of the positive representations is `0`, so the
 * magnitude of the largest positive number is one less than the magnitude of
 * the largest negative number. Hence the initial n = -n causes an integer
 * overflow for INT_MIN.
 *
 * @version 0.1
 * @date 2025-04-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <limits.h>
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
 * @brief Write a string representation of n in s
 *
 * @param n integer to write
 * @param s string to store representation of n
 *
 * @warning s must be large enough to store the conversion.
 */
void itoa(int n, char s[]);

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
    if (!test_itoa(0, "0")) { return EXIT_FAILURE; }
    if (!test_itoa(-0, "0")) { return EXIT_FAILURE; }
    if (!test_itoa(1, "1")) { return EXIT_FAILURE; }
    if (!test_itoa(-1, "-1")) { return EXIT_FAILURE; }
    if (!test_itoa(9, "9")) { return EXIT_FAILURE; }
    if (!test_itoa(-9, "-9")) { return EXIT_FAILURE; }
    if (!test_itoa(12345, "12345")) { return EXIT_FAILURE; }
    if (!test_itoa(-12345, "-12345")) { return EXIT_FAILURE; }

    unsigned width = unsigned_width();
    if (width == 16) {
        if (!test_itoa(INT_MIN, "-32768")) { return EXIT_FAILURE; }
    } else if (width == 32) {
        if (!test_itoa(INT_MIN, "-2147483648")) { return EXIT_FAILURE; }
    } else {
        printf("INT_MIN test not supported for int width: %u\n", width);
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void itoa(int n, char s[]) {
    int sign = n;
    int i = 0;
    do { s[i++] = abs(n % 10) + '0'; } while ((n /= 10));
    if (sign < 0) { s[i++] = '-'; }
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

unsigned unsigned_width(void) {
    unsigned i = 0;
    for (unsigned j = 1; j > 0; j = j << 1U) { ++i; }
    return i;
}