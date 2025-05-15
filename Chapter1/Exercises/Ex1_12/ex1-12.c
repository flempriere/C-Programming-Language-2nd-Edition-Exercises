/**
 * @file ex1-12.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.12 from The C Programming Language, 2nd Edition
 *
 * Write a program that prints its input one word per line.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Indicates the read is currently in a blank substring
 *
 * @see OUT
 */
#define IN 1

/**
 * @brief Indicates the read is not in a blank substring
 *
 * @see IN
 */
#define OUT 0

/**
 * @brief Prints the input one word at a time. Substrings containing multiple
 * blanks are treated as one blank.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int state = IN;
    for (char c; (c = getchar()) != EOF;) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state != IN) {
                putchar('\n');
                state = IN;
            }
        } else {
            state = OUT;
            putchar(c);
        }
    }
    return EXIT_SUCCESS;
}