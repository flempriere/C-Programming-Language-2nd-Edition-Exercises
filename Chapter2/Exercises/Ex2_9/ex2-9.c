/**
 * @file ex2-9.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2.9 from The C Programming Language, 2nd Edition
 *
 * In a two's complement number system $`x &= (x - 1)`$ deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster version of
 *
 * Why?
 * Two's complement:
 * - highest bit represents the sign
 * - positive numbers represented as 0[number in binary]
 * - negative acheived by taking complement of abs value and adding 1.
 *
 * x - 1 -> x + (-1)
 * has repr
 *      xxxx 1000 <- explicit example
 *      1111 1111 etc.
 *      ---- ----
 *      xxxx 0111
 * Since x + '1' + '1' = x + '0' with carry propagating.
 * i.e. carry from 1-bit columns, ensures all values up to (and including) next
 * 1-bit column remain the same. The lowest 1-bit column has no carry digit to
 * set it back to 1 so stays as zero. Anding therefore eliminates it, and leaves
 * all other columns set to 1 in x unchanged.
 *
 * @version 0.1
 * @date 2025-04-27
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
 * @brief Fast implementation of bitcount relying on a Two's-complement
 * representation of signed integers.
 *
 * @param x Value to count the number of set bits.
 * @return Number of set bits in x.
 */
int fast_bitcount(unsigned int x);

/**
 * @brief Tests fast_bitcount, by applying it to argument x, and
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
 * @brief Test driver for fast_bitcount.
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
    for (b = 0; x != 0; x &= x - 1) { b++; }
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