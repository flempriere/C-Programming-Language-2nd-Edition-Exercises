/**
 * @file ex1-17.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.17 from The C Programming Language, 2nd Edition
 *
 * Write a program to print all input lines that are longer than 80 characters.
 *
 * @remark We ignore the newline character in this count.
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Largest line we can read in.
 *
 */
#define MAXLINE 1000

/**
 * @brief Threshold value, such that all lines
 * with lengths greater than PRINT_SIZE are printed.
 *
 */
#define PRINT_SIZE 80

/**
 * @brief Reads a line from standard input and returns the
 * length of the line read. This variant strips newlines.
 *
 * @param maxline maximum size of an input line.
 * @param line buffer to store the read line in, the indices [0, maxline) must
 * be valid.
 *
 * @return length of the read input line, 0 is returned if no line is read.
 */
int get_line(int maxline, char line[]);

/**
 * @brief Reads in lines from input and prints all of them with a length
 * greater than PRINT_SIZE.
 *
 * @return EXIT_SUCESS
 */
int main(void) {
    char line[MAXLINE];

    int len = 0;
    while ((len = get_line(MAXLINE, line)) > 0) {
        if (len > PRINT_SIZE) { printf("%s\n", line); }
    }
    return EXIT_SUCCESS;
}

int get_line(int maxline, char line[]) {
    int i;
    int c = EOF;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}