/*Peforms basic syntax analysis

As a simpliyfing assumption we assume that
there are no comments (these can be removed
via running ex1-23 on the source first) */

/*Need to check for
- unbalanced parantheses, etc
- missing double/single quotes
- interleaved parantheses etc

Since we are purely doing syntax checking we will assume char declarations
like 'aaa' are valid even if they are arithmetically meaningless
(because it's easier)*/

#include <stdio.h>

#define N_SYMBOLS 5

#define UNBALANCED_PARENTHESES 1
#define UNBALANCED_BRACKETS 2
#define UNBALANCED_BRACES 3
#define MISSING_SINGE_QUOTE 4
#define MISSING_DOUBLE_QUOTE 5
#define STACK_OVERFLOW 6
#define PUSHED 7
#define POPPED 8
#define ESCAPE_CHARACTER 9

#define NOT_IN_TEXT 0
#define IN_CHAR 1
#define IN_STR 2



void initialise_array(int a[], int len, int val);
int check_error(int c, int a[], int top, int len);
int check_compatible(int c, int a[], int top);
int in_text(int a[], int top);
int pop_stack(int a[], int top);
int push_stack(int val, int a[], int top, int len);
int get_error(int a[], int top);
void print_error(int error_code, int line);

int main(void) {
    int stack[N_SYMBOLS];
    int c, stack_top, line, error;
    c = stack_top = line = error = 0;
    initialise_array(stack, N_SYMBOLS, 0);

    while ((c = getchar())!= EOF && !error) {
        printf("%c", c);
        error = check_error(c, stack, stack_top, N_SYMBOLS);
        if (error == PUSHED) {++stack_top; error = 0;}
        else if (error == POPPED) {--stack_top; error = 0;}
        if (!error && c == '\n') {++line; printf("\n");}
    }
    if (!error) {
        if (stack_top != 0) {
            error = get_error(stack, stack_top);
        }
    }
    print_error(error, line);
    return 0;
}

void initialise_array(int a[], int len, int val)
{
    for (int i = 0; i < len; i++) a[i] = val;
}

int check_error(int c, int a[], int top, int len)
{
    int error = 0;
    int txt_status = 0;

    //check if we're in a text element
    if (!((txt_status = in_text(a, top)) == NOT_IN_TEXT)) {
        if (txt_status == IN_CHAR) {
            if (c == '\'') {pop_stack(a, top); error = POPPED;}
        }
        else if (txt_status == IN_STR) {
            if (c == '\"') {pop_stack(a, top); error = POPPED;}
        }
    }
    //not in text -> check left braces
    else if  (c == '(' || c == '[' || c == '{') {
        error = push_stack(c, a, top, len);
        if (!error) {error = PUSHED;}
    }
    //not in text -> check right braces
    else if (c == ')' || c == ']' || c == '}') {
        error = check_compatible(c, a, top);
        if (!error) {pop_stack(a, top); error = POPPED;}
    }
    //not in text -> check if we start text
    else if (c == '\'' || c == '\"') {
        error = push_stack(c, a, top, len);
        if (!error) {error = PUSHED;}
    }
    return error;
}

int check_compatible(int c, int a[], int top)
{
    int return_value = 0;
    if (c == '}' && a[top-1] != '{') return_value = UNBALANCED_BRACES;
    else if (c == ']' && a[top-1] != '[') return_value = UNBALANCED_BRACKETS;
    else if (c == ')' && a[top-1] != '(') return_value = UNBALANCED_PARENTHESES;
    return return_value;
}

int in_text(int a[], int top)
{
    int return_status = 0;
    if (!top == 0) {
        if (a[top - 1] == '\"') {return_status = IN_STR;}
        else if (a[top - 1] == '\'') {return_status = IN_CHAR;}
    }
    return return_status;
}

int pop_stack(int a[], int top)
{
    int return_status = 1;
    if (top) {
        a[top - 1] = 0;
        return 0;
    }
    return return_status;
}

int push_stack(int val, int a[], int top, int len) {
    int return_status = 0;
    
    if (top >= len) return_status = STACK_OVERFLOW;
    else {
        a[top] = val;
    }
    return return_status;
}

int get_error(int a[], int top)
{
    int error = 0;
    int c = a[top - 1];
    if (c == '{') error = UNBALANCED_BRACES;
    else if (c == '[') error = UNBALANCED_BRACKETS;
    else if (c == '(') error = UNBALANCED_PARENTHESES;
    else if (c == '\'') error = MISSING_SINGE_QUOTE;
    else if (c == '\"') error = MISSING_DOUBLE_QUOTE;
    return error;
}

void print_error(int error_code, int line)
{
    if (error_code == UNBALANCED_BRACES) {
        printf("unbalanced braces found on line %d\n", line);
    }
    else if (error_code == UNBALANCED_BRACKETS) {
        printf("unbalanced brackets found on line %d\n", line);
    }
    else if (error_code == UNBALANCED_PARENTHESES) {
        printf("unbalanced parentheses found on line %d\n", line);
    }
    else if (error_code == MISSING_SINGE_QUOTE) {
        printf("unbalanced single quote on line %d\n", line);
    }
    else if (error_code == MISSING_DOUBLE_QUOTE) {
        printf("unbalanced double quote on line %d\n", line);
    }
    else if (error_code == STACK_OVERFLOW) {
        printf("error stack overflow occured..., increase stack limit\n");
    }
    else {
        printf("unidentified error code...\n");
    }
    return;
}
