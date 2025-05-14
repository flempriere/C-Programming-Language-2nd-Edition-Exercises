/**
 * @file set_tab.c
 * @author Felix Lempriere
 * @brief set tab functionality in partial fulfillment of Exercise 5.12 from
 * The C Programming Language, 2nd Edition.
 *
 * Extends the implementation in 5.11 to support setting a frequency for tab
 * stops and a start column.
 *
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
 * @brief Tracks the tab stop frequency
 *
 */
static int TABS_frequency = DEFAULT_TABSTOP;

/**
 * @brief Default starting column.
 *
 */
static int TABS_start_col = DEFAULT_START_COL;

/**
 * @brief Gets the next frequency tab stop
 *
 * @param col index of the column.
 */
#define FREQUENCY_NEXT_TAB(col) \
    ((col) + (TABS_frequency - (col - TABS_start_col) % TABS_frequency))

void set_tab_list(int m, int tabs[]) {
    ap = 0;
    n_tabs = m;
    for (int i = 0; i < m; i++) { a[i] = tabs[i]; }
}

void set_tab_frequency(int frequency, int start_col) {
    if (start_col) {
        TABS_start_col = start_col;
    } else {
        TABS_start_col = (n_tabs) ? a[n_tabs - 1] : DEFAULT_START_COL;
    }
}

int next_tab(int col) {
    // generate least upper bound from the tab list
    for (ap = (col < prev ? 0 : ap); ap < n_tabs && a[ap] <= col; ap++);
    // generate least upper bound from the frequency method
    int freq =
        (col < TABS_start_col) ? TABS_start_col : FREQUENCY_NEXT_TAB(col);
    return (prev = (ap < n_tabs) ? ((a[ap] < freq) ? a[ap] : freq) : freq);
}