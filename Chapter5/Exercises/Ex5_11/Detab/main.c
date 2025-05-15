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

#include <stdio.h>
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
    if (--argc > MAXTABS) {
        printf("Error: Exceeded max tabstops\n");
        return EXIT_FAILURE;
    }
    if (argc) {
        argv++;
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
        set_tabs(m, tabs);
    }
    detab();
    return EXIT_SUCCESS;
}