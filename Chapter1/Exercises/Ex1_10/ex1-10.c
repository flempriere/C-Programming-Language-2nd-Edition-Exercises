/**
 * @file ex1-10.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.10 from The C Programming Language, 2nd Edition
 *
 * Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \\b, and each backslash by \\. This makes tabs and spaces
 * visible in an unambigious way.
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
 * @brief Replaces escape characters with their blackslash representation.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    for (int c; (c = getchar()) != EOF;) {
        if (c == '\t') {
            putchar('\\');
            c = 't';
        }
        if (c == '\b') {
            putchar('\\');
            c = 'b';
        }
        if (c == '\\') {
            putchar('\\');
            c = '\\';
        }
        putchar(c);
    }
    return EXIT_SUCCESS;
}