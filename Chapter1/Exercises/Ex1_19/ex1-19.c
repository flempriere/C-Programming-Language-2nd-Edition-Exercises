/**
 * @file ex1-19.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.19 from The C Programming Language, 2nd
 * Edition.
 *
 * Write a function `reverse(s)` that reverses the character string s. Use it
 * to write a program that reverses its input a line at a time.
 * @version 0.1
 * @date 2025-04-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum length of an input line
 *
 */
#define MAXLINE 1000

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
 * @brief reverses a string.
 *
 * Reverses the string stored in s. The reverse
 * is performed inplace.
 *
 * @param s buffer storing the string.
 */
void reverse(char s[]);

/**
 * @brief Reads lines from standard input and prints
 * their reversed contents.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char line[MAXLINE];

    while (get_line(MAXLINE, line) > 0) {
        reverse(line);
        printf("%s\n", line);
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

void reverse(char s[]) {
    int i = 0;
    // find the end of the string
    int len = 0;
    for (len = 0; s[len] != '\0'; len++);
    // perform the reverse
    for (int tmp; i < len / 2; i++) {
        tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}