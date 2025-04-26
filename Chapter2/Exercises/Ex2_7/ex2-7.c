/**
 * @file ex2-7.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.7 from The C Programming Language, 2nd Edition.
 *
 * Write a function `invert(x, p, n)` that returns `x` with the `n` bits that
 * begin at position `p` inverted (i.e. 1 -> 0 and vice-versa), leaving the
 * others unchanged.
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
 * @brief Inverts the n bits of x starting at p, leaving the others
 * untouched.
 *
 * @param x value to invert.
 * @param p Starting index of the bits to inverse, assuming the rightmost idx
 * is 0.
 * @param n Number of bits to invert, the inverted bits are p ... p - (n - 1).
 * @return x with the n bits starting at p inverted.
 */
unsigned invert(unsigned x, unsigned p, unsigned n);

/**
 * @brief Compares the result of invert to an expected value, and prints
 * error diagnostics if they don't agree.
 *
 * @param result Computed result
 * @param expected expected result
 * @return 1 if the values match, else
 * @return 0.
 */
int test_invert(unsigned result, unsigned expected);

/**
 * @brief Test driver for invert.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    unsigned int x = 0x0c3f;

    if (!test_invert(invert(x, 3, 4), 0x0c30)) { return EXIT_FAILURE; }
    if (!test_invert(invert(x, 7, 4), 0x0ccf)) { return EXIT_FAILURE; }
    if (!test_invert(invert(x, 11, 4), 0x033f)) { return EXIT_FAILURE; }
    if (!test_invert(invert(x, 15, 4), 0xfc3f)) { return EXIT_FAILURE; }
    if (!test_invert(invert(x, 0, 1), 0x0c3e)) { return EXIT_FAILURE; }
    if (!test_invert(invert(x, 15, 1), 0x8c3f)) { return EXIT_FAILURE; }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

unsigned int invert(unsigned x, unsigned p, unsigned n) {
    return x ^ (~(~0U << n) << (p - n + 1));
}

int test_invert(unsigned result, unsigned expected) {
    if (result != expected) {
        printf("Error: bitpattern: %x, expected: %x\n", result, expected);
        return 0;
    }
    return 1;
}