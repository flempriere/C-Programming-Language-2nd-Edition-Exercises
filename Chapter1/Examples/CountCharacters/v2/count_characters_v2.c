/**
 * @file count_characters_v2.c
 * @author Felix Lempriere
 * @brief Alternative version of count_characters using a for
 * loop and a double to give a large range for count.
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
 * @brief Counts the number of characters in an input stream.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    double nc;
    for (nc = 0.0; getchar() != EOF; ++nc);
    printf("%.0f\n", nc);
    return EXIT_SUCCESS;
}