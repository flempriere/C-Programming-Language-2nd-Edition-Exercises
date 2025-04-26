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
 * @brief Counts the number of set (1) bits in a given unsigned int x.
 * 
 * @param x 
 * @return int 
 */
int bitcount(unsigned x);

int main(void) {
    return EXIT_SUCCESS;
}

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) { b++; }
    }
    return b;
}