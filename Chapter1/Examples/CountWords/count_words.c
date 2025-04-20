/**
 * @file count_words.c
 * @author Felix Lempriere
 * @brief Counts lines, words and characters.
 *
 * A word is a substring of non-blank, tab or newline.
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Indicates the read is inside a word.
 *
 */
#define IN 1

/**
 * @brief Indicates the read is outside of a word.
 *
 */
#define OUT 0
/**
 * @brief Counts the number of characters, newlines and tabs
 * in a given input stream.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int state = OUT;
    int nl, nw, nc;
    nl = nw = nc = 0;
    int prev = EOF;
    for (char c; (c = getchar()) != EOF; ) {
        ++nc;
        if (c == '\n') ++nl;
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
        prev = c;
    }
    if (prev != EOF && prev != '\n') ++nl;
    printf("Lines: %d Words: %d Characters: %d\n", nl, nw, nc);
    return EXIT_SUCCESS;
}