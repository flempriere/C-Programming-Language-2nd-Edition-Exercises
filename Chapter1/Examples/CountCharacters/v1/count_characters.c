/**
 * @file count_characters.c
 * @author Felix Lempriere
 * @brief A program to count the number of characters in the given input stream.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Counts the number of characters in the input and prints
 * the result to stdout.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    long nc = 0;
    while (getchar() != EOF) { ++nc; }
    printf("%ld\n", nc);
    return EXIT_SUCCESS;
}