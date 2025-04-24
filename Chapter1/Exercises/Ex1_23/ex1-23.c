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

// parsing states

/**
 * @brief Denote we're in a multiline comment
 *
 */
#define MULTILINE_COMMENT 4

/**
 * @brief Denote we're in a singleline comment
 *
 */
#define SINGLELINE_COMMENT 3

/**
 * @brief Denote that we're in a string literal
 *
 */
#define IN_STRING 2

/**
 * @brief Denote that we're in a character literal
 *
 */
#define IN_CHAR 1

/**
 * @brief Value indicating truth
 *
 */
#define TRUE 1

/**
 * @brief Value indicating false
 *
 */
#define FALSE 0

/**
 * @brief Ordinary parsing state.
 *
 */
#define NORMAL 0

/**
 * @brief Removes all comments from the given input file. Handles both
 * traditional multiline comments and singleline comments.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int state = NORMAL;
    int prev = EOF;

    for (char c; (c = getchar()) != EOF;) {
        if (state == NORMAL) {
            if (c == '/') {
                if (prev == '/') { state = SINGLELINE_COMMENT; }
            } else if (c == '*') {
                if (prev == '/') {
                    state = MULTILINE_COMMENT;
                } else {
                    putchar('*');
                }
            } else if (c == '"') {
                state = IN_STRING;
                if (prev == '/') { putchar(prev); }
                putchar(c);
            } else if (c == '\'') {
                state = IN_CHAR;
                if (prev == '/') { putchar(prev); }
                putchar(c);
            } else {
                if (prev == '/') { putchar(prev); }
                putchar(c);
            }
        } else if (state == IN_CHAR) {
            if (c == '\'') { state = NORMAL; }
            putchar(c);
        } else if (state == IN_STRING) {
            if (c == '"') { state = NORMAL; }
            putchar(c);
        } else if (state == SINGLELINE_COMMENT) {
            if (c == '\n') {
                state = NORMAL;
                putchar('\n');
            }
        } else if (state == MULTILINE_COMMENT) {
            if (c == '/' && prev == '*') {
                state = NORMAL;
                c = EOF;    // make it so /**/* does not register as a comment
            }
        }
        prev = c;
    }
    return EXIT_SUCCESS;
}
