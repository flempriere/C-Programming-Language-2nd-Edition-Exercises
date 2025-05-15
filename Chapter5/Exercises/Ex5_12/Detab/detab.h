/**
 * @file detab.h
 * @author Felix Lempriere
 * @brief Header file for detab containing macro and function definitions for
 * managing the tab list.
 *
 * @version 0.1
 * @date 2025-05-15
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
  * @brief The default frequency of tabstops.
  *
  * @see DEFAULT_START, @see set_tab_frequency
  */
 #define DEFAULT_FREQUENCY 8

/**
 * @brief The default start column for frequency based tabbing.
 *
 * @see DEFAULT_FREQUENCY, @see set_tab_frequency
 */
#define DEFAULT_START 1

/**
 * @brief Configures tab stops to be generated from the array
 * tabs on size m.
 *
 * @param m size of the list of tab stops
 * @param tabs ascending non-duplicate array of tabs
 *
 * @pre tabs must an array sorted in ascending order with no
 * duplicates.
 *
 * @warning Calling set_tab_list sets the start column for frequency based
 * tabbing to the last element of the tab list. If this is not desired call
 * set_tab_frequency after calling set_tab_list.
 *
 * @see set_tab_frequency
 */
void set_tab_list(int m, int tabs[]);

/**
 * @brief Sets the tab frequency
 * 
 * Sets tabstops to occur every freq columns starting from start. 
 * - If freq is passed as 0, the frequency is set to DEFAULT_FREQUENCY.
 * - If start is  passed as 0, the start column is inferred as follows,
 *  - If the tab_list is non-empty, the start col is the last tab in the list
 *  - If the tab_list is empty, the start_col is DEFAULT_START
 *
 * @param freq frequency of tab stops
 * @param start starting column of tab stops
 * 
 * @see DEFAULT_START, @see DEFAULT_FREQ
 */
 void set_tab_frequency(int freq, int start);

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
 