/**
 * @file main.c
 * @author Felix Lempriere
 * @brief Implementation of Detab in partial fulfillment of Exercise 5.11 from
 * The C Programming Language, 2nd Edition.
 *
 *
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "detab.h"

#include <stdlib.h>

/**
 * @brief Detabs a file, taking a custom list of tab stops as command line
 input.
 *
 * Detabs a file converting tabs to spaces, using either a default of tabstops
 * every TABSTOP columns, or taing a user supplied list of tabstops. If the user
 * supplied list is exhausted, the default tabstops are used as a fallback.
 *
 * @param argc Number of arguments
 * @param argv List of columns to be used as tabstops.
 *
 * @warning Assumes the tab stop list is an ascending list of numbers,
 * duplicated or  non-ascending numbers will be ignored. Non-numeric inputs
 * will cause undefined behaviour.
 *
 * @return EXIT_SUCCESS if program successfully detabed, else
 * @return EXIT_FAILURE.
 */
int main(int argc, char* argv[]) {
    // parse arguments
    int start = 0;    // 0 -> infers from tab list if not set
    int freq = DEFAULT_FREQUENCY;
    for (--argc, ++argv; argc; argc--, argv++) {
        switch (*argv[0]) {
        case '-':
            start = atoi(*argv + 1);
            break;
        case '+':
            freq = atoi(*argv + 1);
            break;
        default:
            goto parse_tab_list;
        }
    }
parse_tab_list:
    if (argc) {
        int tabs[MAXTABS];
        // convert arguments to non-duplicate ascending list.
        int m = 0;
        int prev = 0;
        for (; argc; argc--) {
            int val = atoi(*argv++);
            if (val > prev) {
                tabs[m++] = val;
                prev = val;
            }
        }
        set_tab_list(m, tabs);
    }
    set_tab_frequency(freq, start);
    detab();
    return EXIT_SUCCESS;
}