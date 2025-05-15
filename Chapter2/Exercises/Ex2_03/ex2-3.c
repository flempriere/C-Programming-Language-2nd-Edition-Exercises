/**
 * @file ex2-3.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.3 from The C Programming Language, 2nd Edition.
 *
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * including an optional (0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 *
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
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
 * @brief Base for hexadecimal numbers.
 *
 */
#define HEX_BASE 16

/**
 * @brief Value of 'a' and 'A' in hexadecimal.
 *
 */
#define A_HEXVAL 10

/**
 * @brief Converts a string representation of a hexadecimal number to
 * the equivalent integer value. May optionally handle a 0x prefix.
 *
 * @param s string representation with optional 0x or 0X factor.
 * @return integer conversion of s.
 */
int htoi(char s[]);

/**
 * @brief Converts a hex digit character to its corresponding integer value.
 *
 * @param c character to convert
 * @return integer value corresponding to the given hexdigit.
 */
int hextoint(int c);

/**
 * @brief Checks if the string has a hexadecimal prefix and returns the number
 * of character digits needed to skip over the prefix.
 *
 * @param s string representation of a hexadecimal number with an optional
 * prefix
 * @return length of the prefix if it exists, else
 * @return 0
 */
int skip_prefix(char s[]);

/**
 * @brief Tests htoi, by converting the given input string
 * and comparing the value to the provided expected value.
 *
 * Prints a diagnostic if the test fails.
 * @param input
 * @param expected
 * @return TRUE if test passed, else
 * @return FALSE
 */
enum truth test_htoi(char input[], int expected);

/**
 * @brief Test driver for htoi function.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    // test decimal boundary
    if (!test_htoi("0", 0)) { return EXIT_FAILURE; }

    // test with prefix
    if (!test_htoi("0x0", 0)) { return EXIT_FAILURE; }
    // test upper decimal boundary
    if (!test_htoi("9", 9)) { return EXIT_FAILURE; }
    if (!test_htoi("0x9", 9)) { return EXIT_FAILURE; }
    // test letter digit lower boundary
    if (!test_htoi("a", 10)) { return EXIT_FAILURE; }
    // test uppercase version
    if (!test_htoi("A", 10)) { return EXIT_FAILURE; }
    if (!test_htoi("0xa", 10)) { return EXIT_FAILURE; }
    // test upper digit boundary
    if (!test_htoi("f", 15)) { return EXIT_FAILURE; }
    if (!test_htoi("0xf", 15)) { return EXIT_FAILURE; }
    if (!test_htoi("0xF", 15)) { return EXIT_FAILURE; }
    // test multidigit string
    if (!test_htoi("0x1f", 31)) { return EXIT_FAILURE; }
    if (!test_htoi("0X1f", 31)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int htoi(char s[]) {
    int n = 0;
    for (int i = skip_prefix(s); isxdigit(s[i]); i++) {
        n = HEX_BASE * n + hextoint(s[i]);
    }
    return n;
}

int hextoint(int c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return (tolower(c) - 'a' + A_HEXVAL);
    }
}

int skip_prefix(char s[]) {
    if (s[0] == '0') {
        if (tolower(s[1]) == 'x') { return 2; }
    }
    return 0;
}

enum truth test_htoi(char input[], int expected) {
    int res = htoi(input);
    if (res != expected) {
        printf("Error: Conversion of %s to %d failed. Result: %d\n", input,
               expected, res);
        return FALSE;
    }
    return TRUE;
}
