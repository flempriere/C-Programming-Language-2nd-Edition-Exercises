/**
 * @file ex3-5.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.5 from The C Programming Language, 2nd Edition.
 *
 * Write the function `itob(n,s,b)` that converts the integer n into a base b
 * character representation in the string s. In particular `itob(n,s,16)`
 * formats n as a hexadecimal number.
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
 * @brief maximum line buffer size.
 *
 */
#define MAX_SIZE 100

/**
 * @brief Largest possible base for itob
 *
 * @see itob
 */
#define MAX_BASE 36

/**
 * @brief enum storing false and true values.
 *
 * FALSE = 0;
 * TRUE = 1
 */
enum truth {
    FALSE,
    TRUE
};

/**
 * @brief Write a string representation of n in s.
 *
 * @param n integer to write.
 * @param s string to store representation of n.
 * @param b base to convert to.
 *
 * @warning s must be large enough to store the conversion.
 * @exception If b is greater than MAX_BASE (or less than 2), an
 * empty string is returned.
 *
 * @see MAX_BASE
 */
void itob(int n, char s[], int b);

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
 * @brief Tests the function itob.
 *
 * Given an input integer n, compares the result of itob(n,s,b) to the expected
 * output. Prints an error diagnostic if they disagree.
 *
 * @param n integer to convert
 * @param b base to convert to.
 * @param expected expected result of itoa(n, s).
 *
 * @return TRUE if the results agree, else
 * @return FALSE
 */
enum truth test_itob(int n, char expected[], int b);

/**
 * @brief Test driver for itoa.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    // normal itoa tests
    if (!test_itob(0, "0", 10)) { return EXIT_FAILURE; }
    if (!test_itob(-0, "0", 10)) { return EXIT_FAILURE; }
    if (!test_itob(1, "1", 10)) { return EXIT_FAILURE; }
    if (!test_itob(-1, "-1", 10)) { return EXIT_FAILURE; }
    if (!test_itob(9, "9", 10)) { return EXIT_FAILURE; }
    if (!test_itob(-9, "-9", 10)) { return EXIT_FAILURE; }
    if (!test_itob(12345, "12345", 10)) { return EXIT_FAILURE; }
    if (!test_itob(-12345, "-12345", 10)) { return EXIT_FAILURE; }

    // testing base smaller than 10
    if (!test_itob(0, "0", 8)) { return EXIT_FAILURE; }
    if (!test_itob(1, "1", 8)) { return EXIT_FAILURE; }
    if (!test_itob(7, "7", 8)) { return EXIT_FAILURE; }
    if (!test_itob(8, "10", 8)) { return EXIT_FAILURE; }
    if (!test_itob(-7, "-7", 8)) { return EXIT_FAILURE; }
    // testing hex base
    if (!test_itob(0, "0", 16)) { return EXIT_FAILURE; }
    if (!test_itob(1, "1", 16)) { return EXIT_FAILURE; }
    if (!test_itob(15, "F", 16)) { return EXIT_FAILURE; }
    if (!test_itob(16, "10", 16)) { return EXIT_FAILURE; }
    if (!test_itob(-7, "-7", 16)) { return EXIT_FAILURE; }
    // testing base-36.
    if (!test_itob(0, "0", 36)) { return EXIT_FAILURE; }
    if (!test_itob(1, "1", 36)) { return EXIT_FAILURE; }
    if (!test_itob(15, "F", 36)) { return EXIT_FAILURE; }
    if (!test_itob(16, "G", 36)) { return EXIT_FAILURE; }
    if (!test_itob(35, "Z", 36)) { return EXIT_FAILURE; }
    if (!test_itob(-7, "-7", 36)) { return EXIT_FAILURE; }
    if (!test_itob(40, "14", 36)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

void itob(int n, char s[], int b) {
    if (b < 2 || b > MAX_BASE) {
        s[0] = '\0';
        return;
    }
    int sign = n;
    int i = 0;
    do {
        int v = abs(n % b);
        s[i++] = v + ((v < 10) ? '0' : ('A' - 10));
    } while ((n /= b));
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

enum truth test_itob(int n, char expected[], int b) {
    char intermediate[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) { intermediate[i] = 0; }

    itob(n, intermediate, b);
    if (strcmp(intermediate, expected)) {
        printf("Error converting %d in base %d produced %s\n", n, b,
               intermediate);
        printf("Expected: %s\n", expected);
        return FALSE;
    }
    return TRUE;
}