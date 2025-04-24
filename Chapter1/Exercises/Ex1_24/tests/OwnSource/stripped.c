

#include <stdio.h>
#include <stdlib.h>


#define N_SYMBOLS 5



#define NO_ERROR 0

#define UNBALANCED_PARENTHESES 1

#define UNBALANCED_BRACKETS 2

#define UNBALANCED_BRACES 3

#define MISSING_SINGLE_QUOTE 4

#define MISSING_DOUBLE_QUOTE 5

#define STACK_OVERFLOW 6



#define NORMAL 0

#define IN_CHAR 1

#define IN_STR 2



#define NOT_ESCAPED 0

#define ESCAPED 1


void initialise_array(int len, int a[], int val);


int check_error(int c, int len, int a[]);


int check_compatible(int c, int a[]);


int in_text(int a[]);


int get_error(int a[]);


void print_error(int error_code, int line);



void pop_stack(int a[]);


int push_stack(int len, int a[], int val);

int stack_top = 0;
int escaped = NOT_ESCAPED;

int main(void) {
    int stack[N_SYMBOLS];
    initialise_array(N_SYMBOLS, stack, 0);

    int error = NO_ERROR;
    int line = 0;
    for (int c; (c = getchar()) != EOF && error == NO_ERROR;) {
        error = check_error(c, N_SYMBOLS, stack);
        if (error == NO_ERROR && c == '\n') { ++line; }
    }
    if (error == NO_ERROR && stack_top != 0) { error = get_error(stack); }
    print_error(error, line);

    return EXIT_SUCCESS;
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
        error = UNBALANCED_BRACES;
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