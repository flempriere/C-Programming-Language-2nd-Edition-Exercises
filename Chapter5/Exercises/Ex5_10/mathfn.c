/**
 * @file mathfn.c
 * @author Felix Lempriere
 * @brief Implementation of the math handling functionality for the basic
 * polish notation calculator.
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "calc.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

void printRangeError(char s[], double x, double lower, double upper) {
    printf("error: value of x %g is invalid for %s.\n", x, s);
    printf("Valid range is [%g, %g]\n", lower, upper);
}

void mathfn(char s[]) {
    /* We use strcmp, since strcmp(s, t) = 0 if equal we have to use note
     * operator ! to invert truthfulness */
    if (!strcmp(s, "help")) {
        printf("Help:\nBasic Command Line Calculator uses Reverse "
               "Polish Notation.\n"
               "Supported operators are: +, -, *, /, %%.\n"
               "Supported functions are: trigonometric, their inverse and "
               "hyperbolic trig,\n"
               "exponential, natural logarithm, log10, sqrt, ceil and floor.\n"
               "The uppercase letters A...Z can be used for variables.\n"
               "To use them replace a number by the letter e.g.\n"
               "\t 3 A +\n"
               "To assign to them use assignment operator = as\n"
               "\tx A =\n"
               "$ - variable that stores the last printed value."
               "Special Commands:\n"
               "\\n - print and pop the top of the stack.\n"
               "? - print top of the stack without popping the item.\n"
               "~ - duplicate the item on top of the stack.\n"
               "@ - swap the two items on top of the stack.\n"
               "# - clear the stack.\n");
    } else if (!strcmp(s, "sin")) {
        push(sin(pop()));
    } else if (!strcmp(s, "cos")) {
        push(cos(pop()));
    } else if (!strcmp(s, "tan")) {
        push(tan(pop()));
    } else if (!strcmp(s, "asin")) {
        double x = pop();
        if (!((x < 1) && (x > -1))) {
            { printRangeError("asin", x, -1, 1); }
        } else {
            push(asin(x));
        }
    } else if (!strcmp(s, "acos")) {
        double x = pop();
        if (!((x < 1) && (x > -1))) {
            { printRangeError("acos", x, -1, 1); }
        } else {
            push(acos(x));
        }
    } else if (!strcmp(s, "atan")) {
        push(atan(pop()));
    } else if (!strcmp(s, "atan2")) {
        double x = pop();
        if (x != 0.0) {
            push(atan2(pop(), x));
        } else {
            printf("Error: zero divisor in function atan2");
        }
    } else if (!strcmp(s, "sinh")) {
        push(sinh(pop()));
    } else if (!strcmp(s, "cosh")) {
        push(cosh(pop()));
    } else if (!strcmp(s, "tanh")) {
        push(tanh(pop()));
    } else if (!strcmp(s, "exp")) {
        push(exp(pop()));
    } else if (!strcmp(s, "log")) {
        push(log(pop()));
    } else if (!strcmp(s, "log10")) {
        push(log10(pop()));
    } else if (!strcmp(s, "pow")) {
        double x = pop();
        push(pow(pop(), x));
    } else if (!strcmp(s, "sqrt")) {
        double x = pop();
        if (x < 0) {
            printf("error: argument of sqrt must be non-negative\n");
        } else {
            push(sqrt(x));
        }
    } else if (!strcmp(s, "ceil")) {
        push(ceil(pop()));
    } else if (!strcmp(s, "floor")) {
        push(floor(pop()));
    } else {
        printf("error: unrecognised function\n");
    }
}