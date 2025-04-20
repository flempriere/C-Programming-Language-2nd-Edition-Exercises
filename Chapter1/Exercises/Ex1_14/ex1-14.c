/**
 * @file ex1-14.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.14 from The C Programming Language, 2nd
 * Edition.
 *
 * Write a program to print a histogram of the frequency of different characters
 * in its input.
 *
 * We restrict ourselves to the printable ascii subset, from 33 to 126.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum index for a char
 *
 */
#define MAX_IDX 256

/**
 * @brief Ascii index of the minimum printable value
 *
 */
#define MIN_PRINT 33

/**
 * @brief Ascii index of the maximum printable value
 *
 */
#define MAX_PRINT 126
/**
 * @brief Prints a histogram of the frequency of different characters in its
 * input.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int charCount[MAX_IDX];
    int max = 0;
    for (int i = 0; i < MAX_IDX; i++) charCount[i] = 0;

    for (int c; (c = getchar()) != EOF;) {
        ++charCount[c];
        if (charCount[c] > max) max = charCount[c];
    }
    for (int i = max + 1; i > 0; i--) {
        printf("%4d|", i);
        for (int j = MIN_PRINT; j <= MAX_PRINT; j++) {
            if (charCount[j] >= i) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    printf("     ");
    for (int i = MIN_PRINT; i < MAX_PRINT; i++) { printf("%c", i); }
    putchar('\n');
    return EXIT_SUCCESS;
}