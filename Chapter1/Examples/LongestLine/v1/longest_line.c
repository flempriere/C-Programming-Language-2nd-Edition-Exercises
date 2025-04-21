/**
 * @file longest_line.c
 * @author Felix Lempriere
 * @brief A program that reads lines from input and prints the longest line to
 * output.
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
 * @brief Maximum length of an input line.
 * 
 */
#define MAXLINE 10

/**
 * @brief Reads a line from standard input and returns the
 * length of the line read.
 * 
 * @param maxline maximum size of an input line.
 * @param s buffer to store the read line in, the indices [0, maxline) must
 * be valid.
 * 
 * @return EXIT_SUCCESS
 */
int get_line(int maxline, char s[maxline]);

/**
 * @brief Copies the string stored in from, to the buffer to.
 * 
 * @param to destination buffer, must be large enough to store the string in
 * from.
 * @param from source buffer, containing a null-terminated string.
 * 
 * @warning Behaviour is undefined if from is not null-terminated, or to is not
 * large enough to store the string in from.
 */
void copy(char to[], char from[]);

/**
 * @brief Reads lines from input and prints the largest line back on standard
 * output.
 * 
 * @return EXIT_SUCCESS 
 */
int main(void) {
    char line[MAXLINE]; //current line
    char longest[MAXLINE]; //current longest line

    int len = 0; //length of the current line
    int max = 0;

    while ((len = get_line(MAXLINE, line)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s\n", longest);
    }
    return EXIT_SUCCESS;
}

int get_line(int maxline, char s[maxline]) {
    int i;
    int c = EOF;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (i < maxline - 1 && c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


void copy(char to[], char from[]) {
    for (int i = 0; (to[i] = from[i]) != '\0';) ++i;
}