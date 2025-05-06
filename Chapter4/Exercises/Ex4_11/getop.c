/**
 * @file getop.c
 * @author Felix Lempriere
 * @brief Implementation of getop defined in the calc.h header.
 * @version 0.1
 * @date 2025-05-06
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "calc.h"

#include <ctype.h>
#include <stdio.h>

int getop(char s[]) {
    int c;
    static int last_c = '\0';

    if (last_c == '\0') {
        c = getch();
    } else {
        c = last_c;
        last_c = '\0';
    }
    while (isblank(s[0] = c)) { c = getch(); }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;    // not a number
    }
    int i = 0;
    if (isdigit(c)) { while (isdigit(s[++i] = c = getch())); }
    if (c == '.') { while (isdigit(s[++i] = c = getch())); }
    s[i] = '\0';
    if (c != EOF) { last_c = c; }
    return NUMBER;
}