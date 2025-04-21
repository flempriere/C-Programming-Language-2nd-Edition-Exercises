/**
 * @file ex1-18.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.18 from The C Programming Language, 2nd Edition
 *
 * Write a program to remove trailing blanks and spaces from each line of input
 * and delete entirely blank lines.
 *
 * @remark This program uses a queue to process blanks, if the queue overflows
 * then elements are popped off the queue to make room for new elements.
 *
 * @warning In the case of an overflow, 
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Number of consecutive blanks that can be stored in the queue
 * 
 */
 #define MAX_BLANKS 2

/**
 * @brief Size of the blank Queue, we need an extra dummy index at the end
 * for proper wrap around behaviour.
 *
 */
#define QUEUE_SIZE MAX_BLANKS + 1

/**
 * @brief Indicates a value is true
 *
 */
#define TRUE 1

/**
 * @brief Indicates a value is false
 *
 */
#define FALSE 0

/**
 * @brief Removes trailing white space and empty lines from an input stream.
 *
 * @remark If a sequence of blanks > QUEUE_SIZE is found, then
 *
 * @return EXIT_SUCCESS if all lines successfully processed, else
 * @return EXIT_FAILURE.
 */
int main(void) {
    char blanks[QUEUE_SIZE];
    for (int i = 0; i < QUEUE_SIZE; i++) { blanks[i] = 0; }

    int tail = 0;             // end of the queue.
    int head = QUEUE_SIZE;    // head of the queue.
    int line_not_empty = FALSE; //indicates a line contains printed characters
    int ret_value = EXIT_SUCCESS; //stores the return value
    int printed_trailing = TRUE; //indicates we have printed trailing whitespace

    for (int c; (c = getchar()) != EOF;) {
        if (c == '\n') {
            //reset the queue
            tail = 0;
            head = QUEUE_SIZE;
            //ignore blank lines
            if (line_not_empty == TRUE) {
                // mark if the program needs to run again
                if (printed_trailing == TRUE) { ret_value = EXIT_FAILURE; }
                putchar('\n');
                line_not_empty = FALSE;
                printed_trailing = FALSE;
            }
        } else if (c == ' ' || c == '\t') {
            //check if queue full, and get first blank if it is.
            if (tail+1 == head) {
                if (head == QUEUE_SIZE) { head = 0; }
                putchar(blanks[head]);
                head = head + 1;
                printed_trailing = TRUE;
                line_not_empty = TRUE;
            }
            //push blanks onto the queue
            blanks[tail] = c;
            tail = tail + 1;
            if (tail == QUEUE_SIZE) { tail = 0; }
        } else {
            //print the queue since found a non-blank
            if (head == QUEUE_SIZE) head = 0;
            while (head != tail) {
                putchar(blanks[head]);
                head = head + 1;
                if (head == QUEUE_SIZE) { head = 0; }
            }
            //print the non-blank and reset for next line
            putchar(c);
            line_not_empty = TRUE;
            printed_trailing = FALSE;
            head = QUEUE_SIZE;
            tail = 0;
        }
    }
    return ret_value;
}