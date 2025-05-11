/**
 * @file getop.c
 * @author Felix Lempriere
 * @brief Implementation of getop for the basic polish notation calculator.
 * @version 0.1
 * @date 2025-05-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[]) {
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    // function
    if (islower(c)) {
        int i = 0;
        while (isalnum(s[++i] = c = getch()));
        ungetch(c);
        s[i] = '\0';
        return MATH_FUNC;
    }
    if (!isdigit(c) && c != '.' && c != '-') { return c; }
    int i = 0;
    if (c == '-' && !(isdigit(s[++i] = c = getch()) || c == '.')) {
        ungetch(c);
        return '-';
    }
    if (isdigit(c)) { while (isdigit(s[++i] = c = getch())); }
    if (c == '.') { while (isdigit(s[++i] = c = getch())); }
    s[i] = '\0';
    if (c != EOF) { ungetch(c); }
    return NUMBER;
}