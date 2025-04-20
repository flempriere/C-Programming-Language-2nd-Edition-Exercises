/**
 * @file ex1-18.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.18 from The C Programming Language, 2nd Edition
 *
 * Write a program to remove trailing blanks and spaces from each line of input
 * and delete entirely blank lines.
 * @version 0.1
 * @date 2025-04-21
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Defines the maximum number of consecutive blanks that
 * can be stored in the blank array.
 * 
 */
#define MAX_BLANKS 1000

int main(void) {
    char blanks[MAX_BLANKS];
    int head = 0;
    int tail = MAX_BLANKS;
    for (char c; (c = getchar()) != EOF; ) {
        if (c == ' ' || c == '\t' || c == '\n') {
            
        }
    }

}