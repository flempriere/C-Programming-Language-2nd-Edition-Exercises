/**
 * @file entab.c
 * @author Felix Lempriere
 * @brief Implements the entabing functionality in partial fulfillment of a
 * solution to Exercise 5.11 from The C Programming Language, 2nd Edition.
 *
 * @version 0.1
 * @date 2025-05-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "entab.h"

#include <stdio.h>

void entab(void) {
    int col = START_COL;
    int n_b = 0;
    int nxt_tab = next_tab(col);
    for (int c; (c = getchar()) != EOF;) {
        switch (c) {
        case ' ':
            n_b++;
            if (col + n_b == nxt_tab) {
                putchar((n_b == 1) ? ' ' : '\t');
                nxt_tab = next_tab(col += n_b);
                n_b = 0;
            }
            break;
        case '\t':
            putchar((col == (nxt_tab - 1)) ? ' ' : '\t');
            nxt_tab = next_tab(col = nxt_tab);
            n_b = 0;
            break;
        default:
            if (c == '\n') {
                col = START_COL;
                nxt_tab = next_tab(col);
            } else {
                col += n_b + 1;
                nxt_tab = (col < nxt_tab) ? nxt_tab : next_tab(col);
            }
            for (; n_b; n_b--) { putchar(' '); }
            putchar(c);
            break;
        }
    }
}