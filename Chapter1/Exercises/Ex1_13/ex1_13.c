/**
 * @file ex1_13.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.13 from The C Programming Language, 2nd
 * Edition.
 *
 * Write a program to print a histogram of the lengths of the words in its
 * input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 *
 *
 * @remark To print a vertical histogram, we keep track of the largest value
 * seen. Then we print each level of the histogram from one above this max (for
 * clarity) down. At each level if the value of a bin is greater or equal to the
 * height we post an asterisk.
 *
 * @version 0.1
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Indicates the read is in a word
 *
 */
#define IN 1

/**
 * @brief Indicates the read is out of a word
 *
 */
#define OUT 0

/**
 * @brief Maximum distinct word length to include in the histogram.
 *
 * Words longer than MAX_WORD_LENGTH will all be binned together.
 */
#define MAX_WORD_LENGTH 30

/**
 * @brief Prints a histogram of the length of words in its input.
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    int wordLengths[MAX_WORD_LENGTH + 2];    // last index stores all larger.
    for (int i = 0; i <= MAX_WORD_LENGTH + 1; i++)
        wordLengths[i] = 0;    // aggregate words larger than MAX_WORD_LENGTH

    int state = OUT;
    int length = 0;
    int max = 0;    // maximum value in a bin we've seen.
    for (char c; (c = getchar()) != EOF;) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                if (length >= MAX_WORD_LENGTH) { length = MAX_WORD_LENGTH + 1; }
                wordLengths[length]++;
                if (wordLengths[length] > max) { max = wordLengths[length]; }
                length = 0;
                state = OUT;
            }
        } else if (state == OUT) {
            state = IN;
            length = 1;
        } else {
            ++length;
        }
    }
    // deal with any trailing word
    if (length != 0) {
        if (length > MAX_WORD_LENGTH) length = MAX_WORD_LENGTH + 1;
        wordLengths[length]++;
        if (wordLengths[length] > max) max = wordLengths[length];
    }
    // print the histogram vertically.
    for (int i = max + 1; i > 0; --i) {
        printf("%4d|", i);
        for (int j = 0; j <= MAX_WORD_LENGTH + 1; j++) {
            putchar(' ');
            if (wordLengths[j] >= i) {
                putchar('*');
            } else {
                putchar(' ');
            }
            putchar(' ');
        }
        putchar('\n');
    }
    printf("     ");
    for (int i = 0; i <= MAX_WORD_LENGTH; i++) { printf("%2d ", i); }
    printf(">%2d\n", MAX_WORD_LENGTH);
    return EXIT_SUCCESS;
}
