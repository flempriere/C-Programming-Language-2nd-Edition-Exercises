/**
 * @file copy_input.c
 * @author Felix Lempriere
 * @brief A simple demonstration of getchar and putchar. This program
 * copies its input to output without modification.
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
 * @brief Copies the input to output.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    return EXIT_SUCCESS;
}