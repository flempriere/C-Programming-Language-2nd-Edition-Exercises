/**
 * @file ex1-16.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.16 from the C Programming Language, 2nd
 * Edition.
 *
 * Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of
 * the text.
 *
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum length of the input line that will be copied.
 *
 */
#define MAXLINE 10

/**
 * @brief Reads a line from standard input and returns the
 * length of the line read.
 *
 * @param maxline maximum size of an input line.
 * @param line buffer to store the read line in, the indices [0, maxline) must
 * be valid.
 *
 * @warning If the input line is terminated with a newline, and the line is
 * bigger than the buffer, it will be stripped.
 * @return length of the input line read, 0 is returned if no line is read.
 */
int get_line(int maxline, char line[maxline]);

/**
 * @brief Copies the string stored in from, to the buffer to.
 *
 * @param dest destination buffer, must be large enough to store the string in
 * from.
 * @param src source buffer, containing a null-terminated string.
 *
 * @warning Behaviour is undefined if from is not null-terminated, or to is not
 * large enough to store the string in from.
 */
void copy(char dest[], char src[]);

/**
 * @brief Reads lines from input and prints the longest line on output as well
 * as its length.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char line[MAXLINE];
    char longest[MAXLINE];

    int max = 0;
    int len = 0;
    while ((len = get_line(MAXLINE, line)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) { printf("Line Length: %d Line: %s\n", max, longest); }
    return EXIT_SUCCESS;
}

int get_line(int maxline, char line[maxline]) {
    int i;
    int c = EOF;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < maxline - 1) line[i] = c;
    }
    if (i < maxline - 1 && c == '\n') {
        line[i] = c;
        ++i;
    }
    if (i > maxline - 1) {
        line[MAXLINE - 1] = '\0';
    } else {
        line[i] = '\0';
    }
    return i;
}

void copy(char src[], char dest[]) {
    for (int i = 0; (src[i] = dest[i]) != '\0';) ++i;
}