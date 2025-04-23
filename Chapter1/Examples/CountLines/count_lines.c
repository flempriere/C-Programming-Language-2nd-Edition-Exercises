/**
 * @file count_lines.c
 * @author Felix Lempriere
 * @brief Counts the lines in a given input stream
 *
 * @bug This example has a bug: If the last line is not terminated
 * by a newline the line count will be off by one.
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
 * @brief Counts the lines in an input stream
 *
 * @bug Line count is off by one, if the final line is not
 * terminated by a newline.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int nl = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') ++nl;
    }
    printf("%d\n", nl);
    return EXIT_SUCCESS;
}