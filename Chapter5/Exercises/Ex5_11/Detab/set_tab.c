/**
 * @file set_tab.c
 * @author Felix Lempriere
 * @brief set tab functionality in partial fulfillment of Exercise 5.11 from
 * The C Programming Language, 2nd Edition.
 *
 * This fragment deals with initialising and generating the appropriate tab
 * stops.
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "detab.h"

/**
 * @brief Number of tabs in the array
 *
 */
static int n_tabs;

/**
 * @brief Array containing tab stops
 *
 */
static int a[MAXTABS];

/**
 * @brief Points to the last tab read.
 *
 */
static int ap;

/**
 * @brief Stores the last passed tab value
 *
 */
static int prev;

/**
 * @brief Gets the next default tabstop after a given column.
 *
 * @param col index of the column.
 */
#define DEFAULT_NEXT_TAB(col) ((col) + (TABSTOP - (col - 1) % TABSTOP))

void set_tabs(int m, int tabs[]) {
    ap = 0;
    n_tabs = m;
    for (int i = 0; i < m; i++) { a[i] = tabs[i]; }
}

int next_tab(int col) {
    // generate least upper bound
    //  could replace this with a binary search
    for (ap = (col < prev ? 0 : ap); ap < n_tabs && a[ap] <= col; ap++);
    return (prev = (ap < n_tabs) ? a[ap] : DEFAULT_NEXT_TAB(col));
}
