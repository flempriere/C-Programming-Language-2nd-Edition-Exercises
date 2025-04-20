/**
 * @file ex1-6.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.6 from The C Programming Language, 2nd Edition.
 *
 * Verify that the expression getchar() != EOF is 0 or 1.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the value of (getchar() != EOF)
 *
 * @remark This will print a 1 for every character in a line
 * including any new lines (enter key).
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int c;
    while ((c = (getchar() != EOF))) { printf("%d\n", c); }
    // printf("%d\n", c);
    return EXIT_SUCCESS;
}