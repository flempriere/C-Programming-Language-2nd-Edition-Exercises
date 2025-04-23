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
 * length of the line read.
 *
 * @remark This variant strips the newline character
 *
 * @param maxline maximum size of an input line.
 * @param s buffer to store the read line in, the indices [0, maxline) must
 * be valid.
 *
 * @return int length of the read line.
 */
int get_line(int maxline, char line[maxline]);

/**
 * @brief reverses a string.
 *
 * Given a string of length len, reverses the input
 * of the string stored in the buffer s. The reverse
 * is performed inplace.
 *
 * @param len length of the string to be reversed.
 * @param s buffer storing the string.
 */
void reverse(int length, char s[length]);

/**
 * @brief Reads lines from standard input and prints
 * their reversed contents.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char line[MAXLINE];
    int len;

    while ((len = get_line(MAXLINE, line)) > 0) {
        reverse(len, line);
        printf("%s\n", line);
    }
    return EXIT_SUCCESS;
}

int get_line(int maxline, char line[maxline]) {
    int i;
    int c = EOF;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    line[i] = '\0';
    return i;
}

void reverse(int len, char s[len]) {
    int i = 0;
    for (int tmp; i < len / 2; i++) {
        tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
}