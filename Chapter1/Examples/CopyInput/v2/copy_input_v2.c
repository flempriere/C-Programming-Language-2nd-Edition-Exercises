/**
 * @file copy_input_v2.c
 * @author Felix Lempriere
 * @brief Improved version of copy_input using operator precedence to be
 * more concise.
 *
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Copies the input to output without modification.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int c;
    while ((c = getchar()) != EOF) { putchar(c); }
    return EXIT_SUCCESS;
}