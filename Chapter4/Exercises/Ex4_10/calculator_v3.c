/**
 * @file calculator.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 4.10 from
 * The C Programming Language, 2nd Edition.
 *
 * An alternative organisation uses `get_line` to read an entire input line;
 * this makes `getch` and `ungetch` unnecessary. Revise the calculator to use
 * approach.
 *
 * @version 0.1
 * @date 2025-04-30
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 * @brief Number of variables
 *
 */
#define N_VARIABLES 27

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

/**
 * @brief Prints the top of the stack without popping it.
 *
 * @return value on top of the stack. The element remains on
 * the stack.
 */
double top(void);

/**
 * @brief Swaps the top two elements of the stack.
 *
 */
void swap(void);

/**
 * @brief Duplicates the element on the top of the stack
 *
 */
void duplicate(void);

/**
 * @brief Clears the stack
 *
 */
void clear(void);

// I/O handling

/**
 * @brief Input buffer
 *
 */
char buf[BUFSIZE];

/**
 * @brief Next free index in the input buffer
 *
 */
int bufp = 0;

/**
 * @brief Read a line of at most lim -1 characters
 * from stdin into the buffer line.
 *
 * @param lim size of the input buffer
 * @param line buffer to store the input
 * @return Number of characters in the line.
 */
int get_line(int lim, char line[]);

/**
 * @brief Push an entire string back onto the input buffer.
 *
 * @remark We chose not to let ungets know about the buffer, but if we
 * did we could perform stricter error handling.
 *
 * @param s string to push back
 */
void ungets(char s[]);

// Calculator Operator Handling

/**
 * @brief Signal that a number was found.
 *
 */
#define NUMBER '0'

/**
 * @brief Indicates a query of the top of the stack
 *
 */
#define TOP '?'

/**
 * @brief Indicates to duplicate the top of the stack
 *
 */
#define DUPLICATE '~'

/**
 * @brief Indicates to swap the top two elements of the stack
 *
 */
#define SWAP '@'

/**
 * @brief Clears the stack
 *
 */
#define CLEAR '#'

/**
 * @brief Indicates a mathematical function has been called
 *
 */
#define MATH_FUNC '1'

/**
 * @brief Indicates variable assignment
 *
 */
#define VARIABLE_ASSIGNMENT '='

/**
 * @brief Symbol for the variable storing the last printed value
 *
 */
#define LAST_PRINTED '$'

/**
 * @brief Gets the next operator or operand
 *
 * @param s buffer to store the next operator or operand.
 *
 * @return int value denoting the operator or variable, this can either be the
 * operator itself, or a symbol denoting that the next op is a math_fn,
 * or a number.
 */
int getop(char s[]);

/**
 * @brief Matches a string to the appropriate mathematical function to call.
 *
 * @param s string containing the name of the mathematical function to call.
 */
void mathfn(char s[]);

/**
 * @brief Prints an error diagnostic if a math function is called with an
 * invalid value.
 *
 * @param s string representation of the math function
 * @param x value the function was called with
 * @param lower lower bound for valid input
 * @param upper upper bound for valid input
 */
void RangeError(char s[], double x, double lower, double upper);

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
    double variables[N_VARIABLES];
    int var = 0;
    for (int i = 0; i < N_VARIABLES; i++) { variables[i++] = 0.0; }

    printf("Welcome to the command line calculator.\n");
    printf("This program uses polish notation e.g x + y -> x y +\n");
    printf("Type help to see the help documentation\n");
    printf(">>: ");
    while (get_line(BUFSIZE, buf)) {
        bufp = 0;
        for (int type; (type = getop(s)) != '\n';) {
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
        variables[N_VARIABLES - 1] = pop();
        printf("\t%.8g\n", variables[N_VARIABLES - 1]);
        printf(">>: ");
    }
    putchar('\n');
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

int getop(char s[]) {
    int c;
    while (isblank(s[0] = c = buf[bufp++]));
    s[1] = '\0';

    // function
    if (islower(c)) {
        int i = 0;
        while (isalnum(s[++i] = c = buf[bufp++]));
        bufp--;
        s[i] = '\0';
        return MATH_FUNC;
    }
    if (!isdigit(c) && c != '.' && c != '-') { return c; }
    int i = 0;
    if (c == '-' && !(isdigit(s[++i] = c = buf[bufp++]) || c == '.')) {
        bufp--;
        return '-';
    }
    if (isdigit(c)) { while (isdigit(s[++i] = c = buf[bufp++])); }
    if (c == '.') { while (isdigit(s[++i] = c = buf[bufp++])); }
    s[i] = '\0';
    if (c != EOF) { --bufp; }
    return NUMBER;
}

void printRangeError(char s[], double x, double lower, double upper) {
    printf("error: value of x %g is invalid for %s.\n", x, s);
    printf("Valid range is [%g, %g]\n", lower, upper);
}

void mathfn(char s[])
/*
We use strncmp, since strcmp(s, t) = 0 if equal we have
to use note operator ! to invert truthfulness
*/
{
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

int get_line(int lim, char line[]) {
    int i = 0;
    int c = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') { line[i++] = c; }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    return i;
}