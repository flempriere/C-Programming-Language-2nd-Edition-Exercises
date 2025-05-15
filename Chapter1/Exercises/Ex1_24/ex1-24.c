/**
 * @file ex1-24.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1.24 from The C Programming Language, 2nd Edition
 *
 * Write a program to check a C program for rudimentary syntax errors like
 * unbalanced parentheses, brackets and braces. Don't forget about quotes, both
 * single and double, escape sequences, and comments. (This program is hard if
 * you do it in full generality.)
 *
 * @remark We will assume the program has been stripped of comments, for example
 * by using ex1-23.
 *
 * @version 0.1
 * @date 2025-04-24
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum depth of the parse stack.
 */
#define N_SYMBOLS 5

// error states

/**
 * @brief Standard no error state.
 */
#define NO_ERROR 0

/**
 * @brief Indicates found an unmatched parentheses.
 */
#define UNBALANCED_PARENTHESES 1

/**
 * @brief Indicates found an unmatched bracket.
 */
#define UNBALANCED_BRACKETS 2

/**
 * @brief Indicates found an unmatched brace.
 */
#define UNBALANCED_BRACES 3

/**
 * @brief Indicates found an unmatched single quote.
 */
#define MISSING_SINGLE_QUOTE 4

/**
 * @brief Indicates found an unmatched double quotes.
 */
#define MISSING_DOUBLE_QUOTE 5

/**
 * @brief Parse stack overflow.
 */
#define STACK_OVERFLOW 6

// parse state

/**
 * @brief Parsing normal syntax.
 */
#define NORMAL 0

/**
 * @brief Parsing inside a char literal ''
 * construct.
 */
#define IN_CHAR 1

/**
 * @brief Parsing inside a string literal " "
 * construct.
 */
#define IN_STR 2

// handling escaped character states

/**
 * @brief Character is not escaped.
 */
#define NOT_ESCAPED 0

/**
 * @brief Character is escaped.
 */
#define ESCAPED 1

/**
 * @brief Initialise the elements of an array a of size len,
 * a value val.

 * @param len size of the array
 * @param a array to initialise
 * @param val value to initialise the array to.
 */
void initialise_array(int len, int a[], int val);

/**
 * @brief Checks if the character c results in a syntax error
 *
 * @param c Character to check
 * @param len size of the parse stack
 * @param a parse stack
 * @return error code
 */
int check_error(int c, int len, int a[]);

/**
 * @brief Checks that a given parenthesis, bracket or brace is compatible
 * with the current symbol on top of the stack
 * @param c symbol to check
 * @param a stack
 * @return error code
 */
int check_compatible(int c, int a[]);

/**
 * @brief Checks if the parser is currently inside a string or character
 * literal.
 *
 * @param a stack
 * @return int indicating what text state we are in, either NORMAL, IN_CHAR or
 * IN_STR
 *
 * @see NORMAL, @see IN_STR, @see IN_CHAR.
 */
int in_text(int a[]);

/**
 * @brief Checks the stack to determine the current error.
 *
 * @param a parse stack
 * @return error state
 */
int get_error(int a[]);

/**
 * @brief Prints a string representation of the current error
 *
 * @param error_code Integer value corresponding to an error code
 * @param line line at which the error was discovered.
 */
void print_error(int error_code, int line);

// stack management

/**
 * @brief Removes the top element of the stack
 *
 * @param a stack
 */
void pop_stack(int a[]);

/**
 * @brief Push an element onto the stack.
 *
 * @param len length of the stack
 * @param a stack
 * @param val value to push
 * @return error code
 */
int push_stack(int len, int a[], int val);

/**
 * @brief Next free index in the stack.
 *
 */
int stack_top = 0;

/**
 * @brief Indicates if we are currently handling an escaped symbol.
 *
 */
int escaped = NOT_ESCAPED;

/**
 * @brief Performs basic syntactic analysis on a C source file.
 *
 * @warning Assumes all comments have already been removed.
 *
 * Currently checks for:
 * - Ensures all grouping symbols {}, [], (), "" and '' are closed.
 *
 * @return EXIT_SUCCESS if no errors are found, else
 * @return EXIT_FAILURE
 */
int main(void) {
    int stack[N_SYMBOLS];
    initialise_array(N_SYMBOLS, stack, 0);

    int error = NO_ERROR;
    int line = 1;
    for (int c; (c = getchar()) != EOF && error == NO_ERROR;) {
        error = check_error(c, N_SYMBOLS, stack);
        if (error == NO_ERROR && c == '\n') { ++line; }
    }
    if (error == NO_ERROR && stack_top != 0) { error = get_error(stack); }
    print_error(error, line);

    if (error == NO_ERROR) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}

void initialise_array(int len, int a[], int val) {
    for (int i = 0; i < len; i++) a[i] = val;
}

int check_error(int c, int len, int a[]) {
    int error = NO_ERROR;
    int state = NORMAL;

    if ((state = in_text(a)) != NORMAL) {
        if (c == '\\' && escaped == NOT_ESCAPED) {
            escaped = ESCAPED;
        } else if (state == IN_CHAR && escaped == NOT_ESCAPED) {
            if (c == '\'') { pop_stack(a); }
        } else if (state == IN_STR && escaped == NOT_ESCAPED) {
            if (c == '"') { pop_stack(a); }
        } else if (escaped == ESCAPED) {
            escaped = NOT_ESCAPED;
        }
    } else if (c == '(' || c == '[' || c == '{') {
        error = push_stack(len, a, c);
    } else if (c == ')' || c == ']' || c == '}') {
        error = check_compatible(c, a);
        if (error == NO_ERROR) pop_stack(a);
    } else if (c == '\'' || c == '"') {
        error = push_stack(len, a, c);
    }
    return error;
}

int check_compatible(int c, int a[]) {
    int error = NO_ERROR;
    if (c == '}' && (stack_top == 0 || a[stack_top - 1] != '{')) {
        error = UNBALANCED_BRACES;
    } else if (c == ']' && (stack_top == 0 || a[stack_top - 1] != '[')) {
        error = UNBALANCED_BRACKETS;
    } else if (c == ')' && (stack_top == 0 || a[stack_top - 1] != '(')) {
        error = UNBALANCED_PARENTHESES;
    }
    return error;
}

int in_text(int a[]) {
    int state = NORMAL;
    if (stack_top > 0) {
        if (a[stack_top - 1] == '"') {
            state = IN_STR;
        } else if (a[stack_top - 1] == '\'') {
            state = IN_CHAR;
        }
    }
    return state;
}

void pop_stack(int a[]) {
    if (stack_top > 0) { a[stack_top - 1] = 0; }
    stack_top--;
}

int push_stack(int len, int a[], int val) {
    if (stack_top >= len) {
        return STACK_OVERFLOW;
    } else {
        a[stack_top] = val;
    }
    stack_top++;
    return NO_ERROR;
}

int get_error(int a[]) {
    int c = a[stack_top - 1];

    int error = NO_ERROR;
    if (c == '{') {
        error = UNBALANCED_BRACES;
    } else if (c == '[') {
        error = UNBALANCED_BRACKETS;
    } else if (c == '(') {
        error = UNBALANCED_PARENTHESES;
    } else if (c == '\'') {
        error = MISSING_SINGLE_QUOTE;
    } else if (c == '"') {
        error = MISSING_DOUBLE_QUOTE;
    }
    return error;
}

void print_error(int error_code, int line) {
    if (!error_code) {
        printf("Syntactic analysis complete, no errors found\n");
    } else if (error_code == UNBALANCED_BRACES) {
        printf("unbalanced braces found on line %d\n", line);
    } else if (error_code == UNBALANCED_BRACKETS) {
        printf("unbalanced brackets found on line %d\n", line);
    } else if (error_code == UNBALANCED_PARENTHESES) {
        printf("unbalanced parentheses found on line %d\n", line);
    } else if (error_code == MISSING_SINGLE_QUOTE) {
        printf("unbalanced single quote on line %d\n", line);
    } else if (error_code == MISSING_DOUBLE_QUOTE) {
        printf("unbalanced double quote on line %d\n", line);
    } else if (error_code == STACK_OVERFLOW) {
        printf("error stack overflow occured..., increase stack limit\n");
    } else {
        printf("unidentified error code...\n");
    }
    return;
}