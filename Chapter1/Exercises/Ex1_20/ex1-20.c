/**
 * @file ex1-20.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.20 from The C Programming Language, 2nd Edition
 *
 * Write a program `detab` that replaces tabs in the input with the proper
 * number of blank spaces to reach the next tab stop. Assume a fixed set of tab
 * stops.
 *
 * @note Should *n* be a variable or symbolic parameter? For now with our level
 * of knowledge it should be a symbolic parameter, since it is defined one and
 * it's value is fixed. in the future, it would be suited as a command-line
 * argument supplied by the user at runtime.
 *
 * @remark We have yet to be introdued to modulus so we need to introduce a
 * function that effectively does the same thing.
 *
 * @version 0.1
 * @date 2025-04-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of columns per tab stop
 *
 */
#define TABSTOP 4

/**
 * @brief detabs a file, converting all tabs to the blanks, keeping the spacing
 * consistent.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    /**
     * @brief Number of spaces to include if a tab is seen.
     *
     */
    int n_spaces = TABSTOP;

    for (int c; (c = getchar()) != EOF;) {
        if (c == '\t') {
            while (n_spaces != 0) {
                putchar(' ');
                n_spaces--;
            }
            n_spaces = TABSTOP;
        } else if (c == '\n') {
            putchar(c);
            n_spaces = TABSTOP;
        } else {
            putchar(c);
            n_spaces--;
            if (n_spaces == 0) { n_spaces = TABSTOP; }
        }
    }
    return EXIT_SUCCESS;
}