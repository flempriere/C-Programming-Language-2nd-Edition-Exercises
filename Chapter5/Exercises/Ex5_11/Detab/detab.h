/**
 * @file detab.h
 * @author Felix Lempriere
 * @brief Header file for detab containing macro and function definitions for
 * managing the tab list.
 *
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

/**
 * @brief Index of the first column.
 *
 */
#define START_COL 1

/**
 * @brief Maximum number of tabs in the tab list.
 *
 */
#define MAXTABS 100

/**
 * @brief The default size frequency of tabstops.
 *
 */
#define TABSTOP 8

/**
 * @brief Configures tab stops to be generated from the array
 * tabs on size m.
 *
 * @param m
 * @param tabs
 *
 * @pre tabs must an array sorted in ascending order with no
 * duplicates.
 */
void set_tabs(int m, int tabs[]);

/**
 * @brief Get the next tab stop after the column col.
 *
 * @param col
 * @return int
 */
int next_tab(int col);

/**
 * @brief Entabs I/O received over stdin, according to the tabstops.
 *
 */
void detab(void);
