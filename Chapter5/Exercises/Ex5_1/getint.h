/**
 * @file getint.h
 * @author Felix Lempriere
 * @brief Header file containing definitions for the getint example.
 * @version 0.1
 * @date 2025-05-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/**
 * @brief Maximum number of integers to read from
 * input.
 */
#define SIZE 10

/**
 * @brief Reads an integer from stdin and stores it in int* pn.
 * 
 * @param pn pointer to address to store parsed int.
 * @return EOF for end-of-file, zero for no conversion, and a positive int
 * following a valid conversion.
 */
int getint(int* pn);

/**
 * @brief Size of the ungetch buffer.
 * 
 */
#define BUFSIZE 100

/**
 * @brief Fetch a character from the input stream.
 * 
 * @return int 
 */
int getch(void);

/**
 * @brief Push a character back onto the getch buffer.
 * 
 * @param c 
 */
void ungetch(int c);