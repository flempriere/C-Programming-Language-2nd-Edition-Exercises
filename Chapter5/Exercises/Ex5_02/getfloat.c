/**
 * @file getfloat.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 5.2 from The C Programming Language, 2nd Edition.
 *
 * Write `getfloat`, the floating-point analog of `getint`. What type does
 * `getfloat` return as its function value.
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "getfloat.h"

#include <ctype.h>
#include <stdio.h>

/**
 * @brief Checks if the character is a EOF, ungetching it if it is not.
 *
 * @param c
 */
#define CHECK_EOF(c)              \
    do {                          \
        if (c != EOF) ungetch(c); \
    } while (0)

/**
 * @brief Increments the numerical expression c by appending the digit d.
 *
 * @param c Number to increment.
 * @param d Digit to append.
 *
 */
#define INCR_DIGIT(c, d) \
    do { c = 10.0 * c + (d - '0'); } while (0)

int getfloat(double* pn) {
    int c;
    while (isspace(c = getch())); /* skip whitespace */

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    int sign = ((c == '-') ? -1 : 1);
    if (c == '+' || c == '-') {
        int d = c;
        if (!(isdigit(c = getch()) || c == '.')) { /*+[-].xyz is valid*/
            ungetch(c); /*loop relies on left->right eval of ||*/
            ungetch(d);
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch()) { INCR_DIGIT(*pn, c); }
    if (c == '.') { c = getch(); }
    double power;
    for (power = 1.0; isdigit(c); c = getch()) {
        INCR_DIGIT(*pn, c);
        power *= 10;
    }
    *pn = sign * *pn / power;

    if (c == 'e' || c == 'E') {
        sign = ((c = getch()) == '-' ? -1 : 1);
        if (c == '+' || c == '-') {
            int d = c;
            if (!isdigit(c = getch())) {
                ungetch(c);
                ungetch(d);
                return 0;
            }
        }
        int exp;
        for (exp = 0; isdigit(c); c = getch()) { INCR_DIGIT(exp, c); }
        if (sign == 1) {
            for (; exp > 0; exp--) *pn *= 10;
        } else
            for (; exp > 0; exp--) *pn /= 10;
    }
    CHECK_EOF(c);
    return c;
}