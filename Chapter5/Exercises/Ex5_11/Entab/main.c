/**
 * @file main.c
 * @author Implementation of Entab in parital fulfillment of Exercise 5.11 from
 * The C Programming Language, 2nd Edition.
 *
 * Extend entab and detab to accept a list of tab stops as arguments. Use the
 * Default tab settings if there are no arguments.
 * @brief
 * @version 0.1
 * @date 2025-05-14
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "entab.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Index of the first column.
 *
 */
#define START_COL 1

/**
 * @brief Entabs a program, replacing strings of blanks and spaces with the
 * minimum number of tabs and spaces to acheive the same spacing.
 *
 * Entab replaces strings of blanks and tabs with the minimum number of blanks
 * and tabs to achieve the same spacing. By default tabs are assumed to be every
 * TABSTOP columns. The program however can be supplied with a list of tab stops
 * to be used instead, falling back to default behaviour if the list is
 * exhausted.
 *
 * @param argc
 * @param argv A list of tab stops in ascending and non-duplicate order.
 *
 * @warning Assumes the tab stop list is an ascending list of numbers,
 * duplicated or  non-ascending numbers will be ignored. Non-numeric inputs
 * will cause undefined behaviour.
 *
 * @return EXIT_SUCCESS after successfully entabing, else
 * @return EXIT_FAILURE.
 */
int main(int argc, char* argv[]) {
    if (--argc > MAXTABS) {
        printf("Error: Exceeded max tabstops\n");
        return EXIT_FAILURE;
    }
    if (argc) {
        argv++;
        int tabs[MAXTABS];
        int m = 0;
        int prev = 0;
        for (; argc; argc--) {
            int val = atoi(*argv++);
            if (val > prev) {
                tabs[m++] = val;
                prev = val;
            }
        }
        set_tabs(m, tabs);
    }
    int col = START_COL;
    int n_blanks = 0;
    int nxt_tab = next_tab(col);
    for (int c; (c = getchar()) != EOF;) {
        switch (c) {
        case '\t':
            if (col == (nxt_tab - 1)) {
                putchar(' ');
            } else {
                putchar('\t');
            }
            nxt_tab = next_tab(col = nxt_tab);
            n_blanks = 0;
            break;
        case ' ':
            if (col == (nxt_tab - 1)) {
                putchar(' ');
                n_blanks = 0;
                nxt_tab = next_tab(col++);
            } else {
                n_blanks++;
                if (col + n_blanks == nxt_tab) {
                    putchar('\t');
                    n_blanks = 0;
                    nxt_tab = next_tab(col += n_blanks);
                }
            }
            break;
        default:
            col += n_blanks + 1;
            for (; n_blanks; n_blanks--) { putchar(' '); }
            putchar(c);
            if (c == '\n') {
                col = START_COL;
                nxt_tab = next_tab(col);
            } else {
                nxt_tab = (col >= nxt_tab) ? next_tab(col) : nxt_tab;
            }
            break;
        }
    }
    return EXIT_SUCCESS;
}