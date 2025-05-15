/**
 * @file main.c
 * @author Felix Lempriere
 * @brief Driver for getint.c as a solution to Exercise 5.1 from The C
 * Programming Language, 2nd Edition.
 *
 * As written `getint` treats a `+` or `-` not followed by a digit as a valid
 * representation of zero. Fix it to push such a character bac on the input.
 *
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "getint.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Driver for getint.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int n, array[SIZE], state;
    printf("Enter integers seperated by whitespace\n");
    for (n = 0; n < SIZE && (state = getint(&array[n])) != EOF; n++);

    for (int j = 0; j < n; j++) { printf("[%d]", array[j]); }
    printf("\n");
    return EXIT_SUCCESS;
}