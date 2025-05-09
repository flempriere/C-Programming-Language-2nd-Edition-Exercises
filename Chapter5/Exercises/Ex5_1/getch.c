/**
 * @file getch.c
 * @author Felix Lempriere
 * @brief Implementation of the file I/O functions in calc.h
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>

/**
 * @brief Maximum size of the input buffer
 *
 */
#define BUFSIZE 100

/**
 * @brief Input buffer
 *
 */
int buf[BUFSIZE];

/**
 * @brief head of the buffer
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