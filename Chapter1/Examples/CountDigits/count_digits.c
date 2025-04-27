/**
 * @file count_digits.c
 * @author Felix Lempriere
 * @brief Counts the number of digits, white spaces and other
 * characters in a given input.
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
 * @brief Counts the occurences of each digit, whitespace and other
 * characters in a given input.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int ndigits[10];
    int nwhite = 0;
    int nother = 0;

    for (int i = 0; i < 10; ++i) { ndigits[i] = 0; }

    for (char c; (c = getchar()) != EOF;) {
        if (c >= '0' && c <= '9') {
            ++ndigits[c - '0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else {
            ++nother;
        }
    }
    printf("digits =");
    for (int i = 0; i < 10; ++i) { printf(" %d", ndigits[i]); }
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return EXIT_SUCCESS;
}