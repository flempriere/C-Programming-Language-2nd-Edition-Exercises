/**
 * @file getbits.c
 * @author Felix Lempriere
 * @brief Extracts the n-bits starting at position p down.
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Gets n bits from position p
 *
 * @param x value to extract the bits from.
 * @param p position to start extraction
 * @param n number of bits to extract.
 * @return unsigned x, with only the bits in the field from p to p + (n - 1)
 * uncleared.
 */
unsigned getbits(unsigned x, unsigned p, unsigned n);

/**
 * @brief Validates the result of getbits, printing an appropriate
 * error message if they disagree.
 *
 * @param result Result of getbits
 * @param expected Expected.
 *
 * @return 1 if the results match, else
 * @return 0.
 */
int test_getbits(unsigned result, unsigned expected);
/**
 * @brief Test driver for getbits.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    unsigned int x = 0x0c3f;

    if (!test_getbits(getbits(x, 3, 4), 0xf)) { return EXIT_FAILURE; }
    if (!test_getbits(getbits(x, 15, 4), 0x0)) { return EXIT_FAILURE; }
    if (!test_getbits(getbits(x, 11, 4), 0xc)) { return EXIT_FAILURE; }
    if (!test_getbits(getbits(x, 7, 4), 0x3)) { return EXIT_FAILURE; }
    if (!test_getbits(getbits(0b1, 0, 1), 0x1)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

unsigned getbits(unsigned x, unsigned p, unsigned n) {
    return (x >> (p + 1 - n)) & ~(~0U << n);
}

int test_getbits(unsigned result, unsigned expected) {
    if (result != expected) {
        printf("Error bitpattern exttracted: %x, expected: %x\n", result,
               expected);
        return 0;
    }
    return 1;
}