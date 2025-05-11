/**
 * @file getch.c
 * @author Felix Lempriere
 * @brief Implementation of getch as part of the basic calculator, in partial
 * fulfillment of Exercise 5.10 from The C Programming Language, 2nd Edition.
 *
 * This version introduces the ability to bind the getch input to a provided
 * array of strings.
 *
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "calc.h"

#include <stdio.h>

/**
 * @brief buffer providing one character of pushback.
 *
 */
static int buf;

/**
 * @brief array of strings used for rebinding the input source for getch.
 *
 */
static char** input = NULL;

/**
 * @brief length of the input array.
 *
 */
static int len;

void set_input(int l, char* s[]) {
    len = l;
    input = s;
}

int getch(void) {
    // read buffer if its full
    if (buf) {
        int c = buf;
        buf = '\0';
        return c;
    }
    // else if input unbound read from stdin
    if (input == NULL) { return getchar(); }
    if (**input == '\0') {
        input++;
        len--;
        return (len) ? ' ' : EOF;    // check if reached end of input.
    }
    return *(*input)++;
}

void ungetch(int c) {
    if (buf) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}