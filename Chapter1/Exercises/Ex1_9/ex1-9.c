/**
 * @file ex1-9.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.9 from The C Programming Language, 2nd Edition.
 *
 * Write a program to copy its input to its output, replacing each substring of
 * one or more blanks by a single blank.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Replaces all substrings of one or more blanks in a given input
 * by a single blank.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int prev = EOF;
    for (int c; (c = getchar()) != EOF;) {
        if (c == ' ') {
            if (prev != ' ') { putchar(c); }
        }
        if (c != ' ') {
            putchar(c);
        }
        prev = c;
    }
    return EXIT_SUCCESS;
}