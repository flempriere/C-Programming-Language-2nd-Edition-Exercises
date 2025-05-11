/**
 * @file stack.c
 * @author Felix Lempriere
 * @brief Stack implementation for the basic command line calculator.
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "calc.h"

#include <stdio.h>

/**
 * @brief Maximum depth of val stack
 *
 */
#define MAXVAL 100

/**
 * @brief Pointer to the next free index on the stack
 *
 */
int sp = 0;

/**
 * @brief Value stack
 *
 */
double val[MAXVAL];

void push(double v) {
    if (sp < MAXVAL) {
        val[sp++] = v;
    } else {
        printf("Error: stack full, can't push %g\n", v);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

double top(void) {
    if (sp > 0) { return val[sp - 1]; }
    printf("error: stack empty\n");
    return 0.0;
}

void duplicate(void) {
    if ((sp > 0) && (sp < MAXVAL)) {
        push(top());
    } else {
        printf("error: stack empty\n");
    }
}

void swap(void) {
    if (sp < 2) {
        printf("error: not enough elements to swap\n");
    } else {
        // Could do this with stack operations if we wanted.
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
}

void clear(void) { sp = 0; }