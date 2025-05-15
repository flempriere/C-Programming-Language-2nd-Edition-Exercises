/**
 * @file set_tab.c
 * @author Felix Lempriere
 * @brief set tab functionality in partial fulfillment of Exercise 5.12 from
 * The C Programming Language, 2nd Edition.
 *
 * Modifies Exercise 5.11's implementation to support a custom frequency based
 * tabstop with an initial column `m` and frequency `n`.
 *
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "detab.h"

#include <stdio.h>

// tab list variables

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

// frequency based tabbing

/**
 * @brief start column for frequency based tabbing
 *
 */
static int TAB_start = DEFAULT_START;

/**
 * @brief frequency of tab stops
 *
 */
static int TAB_freq = DEFAULT_FREQUENCY;

/**
 * @brief Gets the next default tabstop after a given column.
 *
 * @param col index of the column.
 *
 * @pre col > TAB_start
 * @post the least upper bound f(n) of  f(n) = start_col + freq * n, s.t
 * f(n) > col.
 */
#define NEXT_FREQUENCY_TAB(col) \
    ((col) + (TAB_freq) - ((col) - TAB_start) % TAB_freq)

// communal variables

/**
 * @brief Stores the last passed tab value
 *
 */
static int prev;

void set_tab_list(int m, int tabs[]) {
    ap = 0;
    n_tabs = m;
    for (int i = 0; i < m; i++) { a[i] = tabs[i]; }
    TAB_start = a[m - 1];
}

void set_tab_frequency(int freq, int start) {
    TAB_freq = (freq) ? freq : DEFAULT_FREQUENCY;
    TAB_start = (start) ? start : ((n_tabs) ? a[n_tabs - 1] : DEFAULT_START);
    fprintf(stderr, "Set Freq: %d, start: %d\n", TAB_freq, TAB_start);
}

int next_tab(int col) {
    // generate least upper bound from tab_list
    for (ap = (col < prev ? 0 : ap); ap < n_tabs && a[ap] <= col; ap++);
    // generate least upper bound from frequency method
    int freq = (col >= TAB_start) ? NEXT_FREQUENCY_TAB(col) : TAB_start;
    fprintf(stderr, "freq: %d\n", freq);
    if (ap < n_tabs && a[ap] < freq) {
        prev = a[ap];
    } else {
        prev = freq;
    }
    return prev;
}
