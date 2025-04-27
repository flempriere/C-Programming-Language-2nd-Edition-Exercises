/**
 * @file count_digits_v2.c
 * @author Felix Lempriere
 * @brief Reimplementation of count_digits from Chapter 1 utilising a switch
 * statement to control the branching.
 * @version 0.1
 * @date 2025-04-27
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of decimal digits
 *
 */
#define N_DIGITS 10
/**
 * @brief Counts digits, white space and other characters.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int nwhite = 0;
    int nother = 0;
    int ndigit[N_DIGITS];
    for (int i = 0; i < N_DIGITS; i++) { ndigit[i] = 0; }
    for (int c; (c = getchar()) != EOF;) {
        switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            ndigit[c - '0']++;
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    printf("digits =");
    for (int i = 0; i < N_DIGITS; i++) { printf(" %d", ndigit[i]); }
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return EXIT_SUCCESS;
}