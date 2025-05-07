/**
 * @file printd.c
 * @author Felix Lempriere
 * @brief Code example demonstrating the use of recursion to print a string
 * representation of a number.
 * @version 0.1
 * @date 2025-05-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * @brief Prints a decimal representation of a number.
 * 
 * @param n 
 */
void printd(int n);

/**
 * @brief Sample driver for printd.
 * 
 * @return EXIT_SUCCESS
 */
int main(void) {

    printf("Input: %d\n", 0);
    printd(0);
    printf("\nInput: %d\n", 1);
    printd(1);
    printf("\nInput: %d\n", -1);
    printd(-1);
    printf("\nInput: %d\n", 12345);
    printd(12345);
    printf("\nInput: %d\n", -12345);
    printd(-12345);
    printf("\nInput: %d\n", INT_MAX);
    printd(INT_MAX);
    printf("\nInput: %d\n", INT_MIN);
    printd(INT_MIN);
    putchar('\n');

    return EXIT_SUCCESS;
}

void printd(int n) {
    if (n < 0) {
        putchar('-');
    }
    if (n / 10) {
        printd((n > 0) ? (n / 10) : -1 * (n / 10));
    }
    putchar(abs(n % 10) + '0');
}