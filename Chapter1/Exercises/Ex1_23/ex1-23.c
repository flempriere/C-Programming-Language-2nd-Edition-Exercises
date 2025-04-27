/**
 * @file ex1-23.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.23 from The C Programming Language, 2nd Edtion.
 *
 * Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments do not
 * nest.
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
 * @brief Parsing state inside a singleline comment block.
 *
 * Removes all chars until end of file, or a newline is reached, returning
 * the last character read.
 *
 * @return Returns the last character read
 */
int remove_singleline_comment(void);

/**
 * @brief Parsing state inside a multiline comment block.
 *
 * Removes all chars until end of file, or a *\/ is found.
 *
 * @return the last character read
 */
int remove_multiline_comment(void);

/**
 * @brief Parsing state inside a string or character literal
 *
 * @param delim delimiter of the block.
 *
 * @return the last character read.
 */
int in_literal(int delim);

/**
 * @brief Removes all comments from the given input file. Handles both
 * traditional multiline comments and singleline comments.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int prev = EOF;

    for (char c; (c = getchar()) != EOF;) {
        if (prev == '/') {
            if (c == '/') {
                c = remove_singleline_comment();
            } else if (c == '*') {
                remove_multiline_comment();
                c = EOF;    // to avoid /* *// being interpreted as two comments
            } else {
                putchar(prev);
            }
        }
        if (c == '"') {
            c = in_literal('"');
        } else if (c == '\'') {
            c = in_literal('\'');
        } else if (c != '/' && c != EOF) {
            putchar(c);
        }
        prev = c;
    }
    return EXIT_SUCCESS;
}

int remove_singleline_comment(void) {
    int c;
    while ((c = getchar()) != EOF && c != '\n');
    return c;
}

int remove_multiline_comment(void) {
    int prev = EOF;
    int c;
    while ((c = getchar()) != EOF && (c != '/' || prev != '*')) { prev = c; }
    return c;
}

int in_literal(int delim) {
    putchar(delim);
    int c;
    while ((c = getchar()) != delim) {
        putchar(c);
        if (c == '\\') { putchar(getchar()); }    // handle escape sequence
    }
    putchar(c);
    return c;
}