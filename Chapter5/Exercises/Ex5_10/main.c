/**
 * @file main.c
 * @author Felix Lempriere
 * @brief Solution to Ex5.10 from The C Programming Language, 2nd Edition.
 *
 * Write the program `epxr`, which evaluates a reverse Polish Notation
 * expression from the command line, where each operator or operand is
 * a seperate argument.
 *
 * For example
 * expr 2 3 4 + *
 *
 * evaluates 2 x (3 + 4) = 14.
 *
 * @remark Note that really what we have to do here is change where our existing
 * calculator program gets the input to getch from. This is the approach we take
 * leaving the majority of the program untouched but modifying getch to allow
 * its I/O source to be rebound, and then updating the main to do this.
 *
 * @remark Additionally the command-line args leave out the last newline from
 * when we entered the script, so rather than requiring the user to supply one
 * we change the final step of our program to  pop the final value on the stack.
 *
 * @version 0.1
 * @date 2025-05-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "calc.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size of operand or operator string.
 *
 */
#define MAXOP 100

/**
 * @brief Number of variables
 *
 */
#define N_VARIABLES 27

/**
 * @brief Basic Calculator
 *
 * @return int
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("error: call structure is eval expression\n");
        return EXIT_FAILURE;
    }

    char s[MAXOP];
    double variables[N_VARIABLES];
    int var = 0;
    for (int i = 0; i < N_VARIABLES; i++) { variables[i++] = 0.0; }

    // ungets arguments into the buffer
    ungetch(EOF);
    ungetch('\n');
    for (argc--; argc > 0; argc--) {
        ungets(" ");    // denote end of input
        ungets(argv[argc]);
    }

    for (int type; (type = getop(s)) != EOF;) {
        int op2;
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case MATH_FUNC:
            mathfn(s);
            break;
        case TOP:
            variables[N_VARIABLES - 1] = top();
            printf("\t%.8g\n", variables[N_VARIABLES - 1]);
            break;
        case DUPLICATE:
            duplicate();
            break;
        case SWAP:
            swap();
            break;
        case CLEAR:
            clear();
            break;
        case VARIABLE_ASSIGNMENT:
            pop();    // clear previous variable assignment
            if (isupper(var)) {
                variables[var - 'A'] = pop();
            } else {
                printf("error: Variable must be uppercase letter\n");
            }
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
        case '%':
            op2 = pop();
            push(fmod(pop(), op2));
            break;
        case '\n':
            variables[N_VARIABLES - 1] = pop();
            printf("\t%.8g\n", variables[N_VARIABLES - 1]);
            printf(">>: ");
            break;
        case LAST_PRINTED:
            push(variables[N_VARIABLES - 1]);
            break;
        default:
            if (isupper(type)) {
                push(variables[type - 'A']);
            } else {
                printf("error: unknown command %s\n", s);
            }
            break;
        }
        var = type;
    }
    return EXIT_SUCCESS;
}