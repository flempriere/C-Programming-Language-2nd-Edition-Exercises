/**
 * @file ex2-8.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.8 from The C Programming Language, 2nd Edition
 *
 * Write a function rightrot(x, n) that returns the value of the integer x
 * rotated to the right by n bit positions.
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
 * @brief Rotates the integer x by n bit positions.
 *
 * @param x integer to rotate.
 * @param n Number of bit positions to rotate by.
 * @return unsigned x rotated right by n.
 */
unsigned rightrot(unsigned x, unsigned n);

/**
 * @brief Tests the implementation of rightrot, by taking
 * in an integer x, and a value n, calling rightrot and
 * checking this against expected.
 *
 * Prints error diagnostics if they disagree.
 *
 * @param x input integer
 * @param n bits to rotate by.
 * @param expected expected output
 * @return TRUE if the result matches the expected, else
 * @return FALSE.
 */
enum truth test_rightrot(unsigned x, unsigned n, unsigned expected);

/**
 * @brief Computes the width of an unsigned int on this computer.
 *
 * @remark Annoyingly we either need to store this globally, or recompute it
 * everytime we call rightrot. Later, once we learn about sizeof, we could use
 * sizeof(unsigned) * CHAR_BIT, or from C23 onwards use UINT_WIDTH.
 *
 * @return int Bit width of unsigned.
 */
unsigned unsigned_width(void);

/**
 * @brief Test driver for rightrot.
 *
 * @return EXIT_SUCCESS if all tests passed, else
 * @return EXIT_FAILURE
 */
int main(void) {
    unsigned int x = 0x0c3f;
    unsigned width = unsigned_width();

    if (!test_rightrot(x, 0, 0x0c3f)) { return EXIT_FAILURE; }
    if (width == 16) {
        if (!test_rightrot(x, 1, 0x8e9f)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 4, 0xf0c3)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 8, 0x3f0c)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 12, 0xc3f0)) { return EXIT_FAILURE; }
    } else if (width == 32) {
        if (!test_rightrot(x, 1, 0x8000061f)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 4, 0xf00000c3)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 8, 0x3f00000c)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 16, 0x0c3f0000)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 20, 0x00c3f000)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 24, 0x000c3f00)) { return EXIT_FAILURE; }
        if (!test_rightrot(x, 28, 0x0000c3f0)) { return EXIT_FAILURE; }
    } else {
        printf("Full test suite not supported for unsigned width %u\n", width);
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

unsigned rightrot(unsigned x, unsigned n) {
    unsigned width = unsigned_width();
    unsigned rotbits = ((x & ~(~0U << n)) << (width - n));
    x = (x >> n) | rotbits;
    return x;
}

enum truth test_rightrot(unsigned x, unsigned n, unsigned expected) {
    unsigned res;
    if ((res = rightrot(x, n)) != expected) {
        printf("Error: input: %x, n: %u\n", x, n);
        printf("Error: bitpattern: %x, expected: %x\n", res, expected);
        return FALSE;
    }
    return TRUE;
}

unsigned unsigned_width(void) {
    unsigned i = 0;
    for (unsigned j = 1; j > 0; j = j << 1U) { ++i; }
    return i;
}