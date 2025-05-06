/**
 * @file calculator.c
 * @author Felix Lempriere
 * @brief A rudimentary calculator implementation.
 *
 * Reads numbers one number per line printing the cumulative sum.
 * @version 0.1
 * @date 2025-04-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

/**
 * @brief Gets a line from standard input and stores it in line.
 *
 * @param line line to read into
 * @param lim maximum size of input
 * @return length of the input line read, if no line is read then,
 * @return 0.
 */
int get_line(char line[], int lim);

/**
 * @brief Basic calculator program for the cumulative sum of reals.
 * 
 * @return EXIT_SUCESS
 */
int main(void) {
    
    char line[MAXLINE];
    double sum = 0.0;
    while (get_line(line, MAXLINE)) {
        printf("\t%g\n", sum += atof(line));
    }
    return EXIT_SUCCESS;
}

int get_line(char line[], int lim) {
    int i = 0;
    int c = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') { line[i++] = c; }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    return i;
}