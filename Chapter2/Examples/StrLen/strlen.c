/**
 * @file strlen.c
 * @author Felix Lempriere
 * @brief Example implementation of strlen.
 *
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

/**
 * @brief Calculates the length of a string s.
 *
 * @param s
 * @return EXIT_SUCCESS
 */
int my_strlen(char s[]);

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Test driver for strlen.
 *
 * Tests the following
 * - empty string
 * - single character string
 * - multicharacter string
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char empty[] = "";
    char single[] = "a";
    char multichar[] = "ab";

    if (my_strlen(empty) != 0) {
        printf("Test failed on empty string\n");
        return EXIT_FAILURE;
    }
    if (my_strlen(single) != 1) {
        printf("Test failed on single character string\n");
        return EXIT_FAILURE;
    }
    if (my_strlen(multichar) != 2) {
        printf("Test failed on multicharacter string\n");
        return EXIT_FAILURE;
    }
    printf("All tests passed\n");
    return EXIT_SUCCESS;
}

int my_strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') { ++i; }
    return i;
}