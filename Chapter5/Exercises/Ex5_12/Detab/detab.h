/**
 * @file detab.h
 * @author Felix Lempriere
 * @brief Header file for detab containing macro and function definitions for
 * managing the tab list.
 *
 * @version 0.1
 * @date 2025-05-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/**
 * @brief Maximum number of tabs in the tab list.
 * 
 */
 #define MAXTABS 100

 /**
  * @brief The default size frequency of tabstops.
  * 
  */
 #define DEFAULT_TABSTOP 8

/**
 * @brief The default column to start tab stops from.
 * 
 */
 #define DEFAULT_START_COL 1
 
/**
* @brief Configures tab stops to be generated from the array
* tabs on size m
* 
* @param m size of the tab arrays
* @param tabs array containing tabs
*
* @remark set_tab_list sets the start column for frequency-based tapping to be
* the last tab stop in the array. To override this call set_tab_frequency after.
* @pre tabs must an array sorted in ascending order with no
* duplicates. 
*/
void set_tab_list(int m, int tabs[]);

/**
 * @brief Sets tab stops to occur every @frequency columns, starting from 
 * start_col.
 *
 * Configures the tabs to generated every frequency columns, starting at the
 * start_col. If an argument of zero is passed to start_col the start_col is
 * inferred as follows,
 *      - If the tab list is set start_col will be the last element of the
 * tab list
 *      - If the tab list is not set, start_col is set to the default start col.
 *
 * @param frequency frequency of tab stops
 * @param start_col starting column for tab stops. If 
 */
void set_tab_frequency(int frequency, int start_col);
 
 /**
  * @brief Get the next tab stop after the column col.
  * 
  * @param col 
  * @return int 
  */
 int next_tab(int col);
 
 
 