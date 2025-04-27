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
 * @brief The size of the printable characters array.
 *
 */
#define PRINTABLE_ARRAY_SIZE (MAX_PRINT - MIN_PRINT + 1)

/**
 * @brief Prints a histogram of the frequency of different characters in its
 * input.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int charCount[PRINTABLE_ARRAY_SIZE + 1];    // avoiding variable length
                                                // array
    int max = 0;
    for (int i = 0; i <= PRINTABLE_ARRAY_SIZE; i++) charCount[i] = 0;

    for (int c; (c = getchar()) != EOF;) {
        if (c < MIN_PRINT || c > MAX_PRINT) {
            c = PRINTABLE_ARRAY_SIZE;
        } else {
            c = c - MIN_PRINT;
        }
        charCount[c]++;
        if (charCount[c] > max) max = charCount[c];
    }
    for (int i = max + 1; i > 0; i--) {
        printf("%4d|", i);
        for (int j = 0; j <= PRINTABLE_ARRAY_SIZE; j++) {
            if (charCount[j] >= i) {
                putchar('*');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    printf("     ");
    for (int i = 0; i < PRINTABLE_ARRAY_SIZE; i++) {
        printf("%c", i + MIN_PRINT);
    }
    printf("Other\n");
    return EXIT_SUCCESS;
}