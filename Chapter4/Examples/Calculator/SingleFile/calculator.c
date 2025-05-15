/**
 * @file calculator.c
 * @author Felix Lempriere
 * @brief Initial Implementation of a basic Polish Notation Calculator.
 * @version 0.1
 * @date 2025-04-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size of operand or operator string.
 *
 */
#define MAXOP 100

/**
 * @brief Maximum depth of val stack
 *
 */
#define MAXVAL 100

/**
 * @brief Maximum size of the input buffer
 *
 */
#define BUFSIZE 100

// Stack

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

/**
 * @brief Push a value onto the stack.
 *
 * @param v
 */
void push(double v);

/**
 * @brief Pop a value from the stack
 *
 * @return value on top of the stack. The item is removed
 * from the stack.
 */
double pop(void);

// I/O handling

/**
 * @brief Input buffer
 *
 */
char buf[BUFSIZ];

/**
 * @brief head of the buffer
 *
 */
int bufp = 0;

/**
 * @brief Signal that a number was found.
 *
 */
#define NUMBER '0'

/**
 * @brief Fetches a character from input.
 *
 * @return next input character
 */
int getch(void);

/**
 * @brief Push a character back onto the input buffer
 *
 * @param c character to push back
 */
void ungetch(int c);

/**
 * @brief Gets the next operator or operand
 *
 * @param s buffer to store the next operator or operand.
 * @return int value denoting the operator, or the that the buffer
 * contains an operand.
 */
int getop(char s[]);

/**
 * @brief A basic calculator that handles reverse polish notation.
 *
 * Supports:
 * - Operators: +, -, /, %, *
 * - Functions: sin, cos, exp, log, etc..
 * - Variables: A, B, ... Z, $ <- last printed
 * - Stack manipulation operations.
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

int getop(char s[]) {
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;    // not a number
    }
    int i = 0;
    if (isdigit(c)) { while (isdigit(s[++i] = c = getch())); }
    if (c == '.') { while (isdigit(s[++i] = c = getch())); }
    s[i] = '\0';
    if (c != EOF) { ungetch(c); }
    return NUMBER;
}

int getch(void) {
    // attempt to read from the buffer
    int val = (bufp > 0) ? buf[--bufp] : getchar();
    return val;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}