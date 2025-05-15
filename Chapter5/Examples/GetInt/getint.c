/**
 * @file getint.c
 * @author Felix Lempriere
 * @brief Demonstrates the use of a pointer to faciliate multiple outputs from
 * a function.
 *
 * Contains the getint implementation.
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
    if (c == '+' || c == '-') { c = getch(); }
    for (*pn = 0; isdigit(c); c = getch()) { *pn = 10 * *pn + (c - '0'); }
    *pn *= sign;
    if (c != EOF) { ungetch(c); }
    return c;
}
