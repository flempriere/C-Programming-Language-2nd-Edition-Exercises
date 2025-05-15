/**
 * @file main.c
 * @author Felix Lempriere
 * @brief Main file implementation for a reverse polish notation calculator.
 * @version 0.1
 * @date 2025-05-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/**
 * @brief Maximum size of operand or operator string.
 *
 */
#define MAXOP 100

/**
 * @brief A basic calculator that handles reverse polish notation.
 *
 * Supports:
 * - Operators: +, -, /, *
 *
 * @return EXIT_SUCCESS
 */
int main(void) {
    char s[MAXOP];

    for (int type; (type = getop(s)) != EOF;) {
        int op2;
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            push(pop() / op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return EXIT_SUCCESS;
}