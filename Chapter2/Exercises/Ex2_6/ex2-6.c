/**
 * @file ex2-6.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.6 from The Programming Language, 2nd Edition.
 *
 * Write a function setbits(x, p, n, y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 *
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief sets the n bits of x starting at position p with the rightmost n
 * bits of y.
 *
 * @param x Integer to set the bits.
 * @param p Starting position to set the bits of, assuming rightmost bit is 0
 * @param n Number of bits to set, the bits are set from bit p, to bit p - (n -
 * 1).
 * @param y Integer to get the bits from.
 *
 * @return unsigned
 */
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

/**
 * @brief Compares the result of setbits to an expected value, and prints
 * error diagnostics if they don't agree.
 *
 * @param result Computed result
 * @param expected expected result
 * @return 1 if the values match, else
 * @return 0.
 */
int test_setbits(unsigned result, unsigned expected);
/**
 * @brief Test driver for setbits.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    unsigned int x = 0x0c3f;
    unsigned int mask = 0x5;

    if (!test_setbits(setbits(x, 3, 4, mask), 0x0c35)) { return EXIT_FAILURE; }
    if (!test_setbits(setbits(x, 7, 4, mask), 0x0c5f)) { return EXIT_FAILURE; }
    if (!test_setbits(setbits(x, 11, 4, mask), 0x053f)) { return EXIT_FAILURE; }
    if (!test_setbits(setbits(x, 15, 4, mask), 0x5c3f)) { return EXIT_FAILURE; }
    if (!test_setbits(setbits(x, 0, 1, mask), 0x0c3f)) { return EXIT_FAILURE; }
    if (!test_setbits(setbits(x, 15, 1, mask), 0x8c3f)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

unsigned int setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
    return (x & ~(~(~0U << n) << (p + 1 - n))) |
           ((y & ~(~0U << n)) << (p + 1 - n));
}

int test_setbits(unsigned result, unsigned expected) {
    if (result != expected) {
        printf("Error: bitpattern: %x, expected: %x\n", result, expected);
        return 0;
    }
    return 1;
}