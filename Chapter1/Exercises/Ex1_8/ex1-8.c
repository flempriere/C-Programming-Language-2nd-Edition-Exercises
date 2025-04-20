/**
 * @file ex1-8.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.8 from The C Programming Language, 2nd Edition
 *
 * Write a program to count blanks, tabs and newlines.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Counts the number of blanks, newlines and tabs in the given input.
 *
 * @note We use a double for blank since we expect significantly more of them
 * than we do tabs and newlines.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    double nb = 0;
    long nt = 0;
    long nl = 0;

    for (int c; (c = getchar()) != EOF;) {
        if (c == '\n') ++nl;
        if (c == '\t') ++nt;
        if (c == ' ') ++nb;
    }
    printf("Lines: %.ld Tabs: %ld Blanks: %.0f\n", nl, nt, nb);
    return EXIT_SUCCESS;
}