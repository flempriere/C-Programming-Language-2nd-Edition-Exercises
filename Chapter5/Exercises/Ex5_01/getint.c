/**
 * @file getint.c
 * @author Felix Lempriere
 * @brief implementation of getint as a solution to Exercise 5.1 from The C
 * Programming Language, 2nd Edition.
 *
 * As written `getint` treats a `+` or `-` not followed by a digit as a valid
 * representation of zero. Fix it to push such a character bac on the input.
 *
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "getint.h"

#include <ctype.h>
#include <stdio.h>

int getint(int* pn) {
    int c;
    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    int sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int d = c;
        if (!isdigit(c = getch())) {
            ungetch(c);
            ungetch(d);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) { *pn = 10 * *pn + (c - '0'); }
    *pn *= sign;
    if (c != EOF) { ungetch(c); }
    return c;
}
