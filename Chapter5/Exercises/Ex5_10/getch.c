/**
 * @file getch.c
 * @author Felix Lempriere
 * @brief Implementation of getch as part of the basic calculator, in partial
 * fulfillment of Exercise 5.10 from The C Programming Language, 2nd Edition.
 *
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "calc.h"

#include <stdio.h>
#include <string.h>

/**
 * @brief Input buffer
 *
 */
char buf[BUFSIZE];

/**
 * @brief Next free index in the input buffer
 *
 */
int bufp = 0;

int getch(void) {
    // attempt to read from the buffer
    int val = (bufp > 0) ? buf[--bufp] : getchar();
    return val;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[]) { for (int len = strlen(s); len > 0; ungetch(s[--len])); }