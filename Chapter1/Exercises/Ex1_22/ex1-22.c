/**
 * @file ex1-22.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.22 from The C Programming Language, 2nd
 * Edition.
 *
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long lines
 * and if there are no blanks or tabs before the specified column.
 *
 * @version 0.1
 * @date 2025-04-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of columns per tabstop.
 *
 */
#define TABSTOP 8

/**
 * @brief Maximum size of a column after being folded.
 *
 */
#define MAX_COL 14

/**
 * @brief Alias for a truth value
 *
 */
#define TRUE 1

/**
 * @brief Alias for a false value
 *
 */
#define FALSE 0

/**
 * @brief Tracks the end of the last word on line.
 *
 */
int word_end = MAX_COL;

/**
 * @brief detabs a tab into the buffer s, calling fold line
 * if needed.
 *
 * @param len total used length of the buffer
 * @param s buffer to store the string
 * @param idx current index in the buffer
 * @return new index in the buffer
 */
int detab(int len, char s[]);

/**
 * @brief Folds the line stored in the buffer
 *
 * @param len total used length of the buffer.
 * @param s buffer to fold.
 * @param idx current max idx in the buffer
 * @return new index in the buffer
 */
int fold_line(int len, char s[]);

/**
 * @brief Checks if the given character is a blank, tab or newline.
 *
 * @param c
 * @return TRUE if blank else FALSE
 *
 * @see TRUE, @see FALSE
 */
int is_blank(int c);

/**
 * @brief Folds the input lines, so that all lines are no wider than
 * MAX_COL. Fold prioritises breaking on whitespace after a completed word where
 * possible.
 *
 * @see MAX_COL
 * @return EXIT_SUCCESS.
 */
int main(void) {
    char split_line[MAX_COL];

    int i = 0;
    int prev = '\n';

    for (int c; (c = getchar()) != EOF;) {
        if (c == '\t') {
            if (is_blank(prev) == FALSE) { word_end = i; }
            i = detab(i, split_line);
        } else if (c == '\n') {
            word_end = MAX_COL;
            fold_line(i, split_line);
            i = 0;
        } else {
            if (c == ' ') { word_end = i; }
            if (i == MAX_COL) { i = fold_line(i, split_line); }
            split_line[i] = c;
            i++;
        }
        prev = c;
    }
    // print any remaining lines in the buffer
    for (int j = 0; j < i; j++) { putchar(split_line[j]); }
    if (i != 0) { putchar('\n'); }

    return EXIT_SUCCESS;
}

int is_blank(int c) {
    if (c == ' ' || c == '\t' || c == '\n') { return TRUE; }
    return FALSE;
}

int detab(int len, char s[]) {
    int n_spaces = len;
    while (n_spaces > TABSTOP) { n_spaces = n_spaces - TABSTOP; }
    n_spaces = TABSTOP - n_spaces;
    if (n_spaces == 0) n_spaces = TABSTOP;

    for (; n_spaces > 0; n_spaces--) {
        if (len == MAX_COL) { len = fold_line(len, s); }
        s[len] = ' ';
        len++;
    }
    return len;
}

int fold_line(int len, char s[]) {
    for (int i = 0; i < word_end && i < len; i++) { putchar(s[i]); }
    putchar('\n');
    // If no complete word or empty line
    if (word_end == MAX_COL) return 0;

    // reset the end of word marker and move the buffer down
    int j = 0;
    for (int k = j + word_end; k < len; k++) {
        s[j] = s[k];
        j++;
    }
    word_end = MAX_COL;
    return j;
}