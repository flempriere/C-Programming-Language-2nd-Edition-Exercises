/**
 * @file bitcount.c
 * @author Felix Lempriere
 * @brief Example program counting the number of set (1) bits in a given
 * integer.
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
 * @brief Counts the number of set (1) bits in a given unsigned int x.
 *
 * @param x
 * @return number of set bits in x.
 */
int bitcount(unsigned x);

/**
 * @brief Tests bitcount, by applying it to argument x, and
 * checking it matches the expected value expected. If the test
 * fails an error diagnostic is printed.
 *
 * @param x Input to bitcount
 * @param expected Expected output of bitcount
 * @return TRUE if test successful, else
 * @return FALSE.
 */
enum truth test_bitcount(unsigned x, unsigned expected);

/**
 * @brief Test driver for bitcount.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    if (!test_bitcount(0x0U, 0)) { return EXIT_FAILURE; }
    if (!test_bitcount(0x1U, 1)) { return EXIT_FAILURE; }
    if (!test_bitcount(0x2U, 1)) { return EXIT_FAILURE; }
    if (!test_bitcount(0x3U, 2)) { return EXIT_FAILURE; }
    if (!test_bitcount(0xa, 2)) { return EXIT_FAILURE; }
    unsigned max = 1U;
    while (max << 1 != 0) { max <<= 1U; }
    if (!test_bitcount(max, 1)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) { b++; }
    }
    return b;
}

enum truth test_bitcount(unsigned x, unsigned expected) {
    unsigned result;
    if ((result = bitcount(x)) != expected) {
        printf("Error:  Failed test: %x\n", x);
        printf("Error: Result: %d, Expected: %d\n", result, expected);
        return FALSE;
    }
    return TRUE;
}