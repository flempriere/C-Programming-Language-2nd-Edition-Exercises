/**
 * @file ex1-21.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.21 from The C Programming Language, 2nd Edition
 *
 * Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab. When either a tab or a single blank would suffice to reach a tab stop
 * which should be given preference?
 *
 * @remark It makes more sense to prioritise a blank space over a tab.
 * @version 0.1
 * @date 2025-04-23
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of columns per tab stop
 *
 */
#define TABSTOP 8

/**
 * @brief entabs a file, replacing strings of blanks and tabs
 * by the minimum number of blanks and tabs to achieve the same
 * spacing.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int n_spaces = 0;    // current number of consecutive spaces
    int spaces_for_tab =
        TABSTOP;    // tracks the number of spaces equal to a tab.

    for (int c; (c = getchar()) != EOF;) {
        if (c == '\t') {    // tab always clears spaces
            if (spaces_for_tab == 1) {
                putchar(' ');    // prioritise blank
            } else {
                putchar('\t');
            }
            n_spaces = 0;    // reset counters
            spaces_for_tab = TABSTOP;
        } else if (c == ' ') {
            if (spaces_for_tab ==
                1) {    // if only need one tab stop prioritise blank
                putchar(' ');
                n_spaces = 0;
                spaces_for_tab = TABSTOP;
            } else {
                // increment spaces and check if we output a tab
                n_spaces++;
                if (n_spaces == spaces_for_tab) {
                    putchar('\t');
                    n_spaces = 0;
                    spaces_for_tab = TABSTOP;
                }
            }
        } else {
            // update the tab counter
            spaces_for_tab = spaces_for_tab - n_spaces;
            if (spaces_for_tab == 0) { spaces_for_tab = TABSTOP; }
            for (; n_spaces > 0; n_spaces--) { putchar(' '); }
            // put the character and update the tab state.
            putchar(c);
            if (c == '\n') {
                spaces_for_tab = TABSTOP;
            } else {
                spaces_for_tab--;
                if (spaces_for_tab == 0) { spaces_for_tab = TABSTOP; }
            }
        }
    }
    return EXIT_SUCCESS;
}