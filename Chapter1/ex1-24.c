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


#define NOT_IN_TEXT 0
#define IN_CHAR 1
#define IN_STR 2

#define NOT_ESCAPED 0
#define ESCAPED 1



void initialise_array(int a[], int len, int val);
int check_error(int c, int a[], int len);
int check_compatible(int c, int a[]);
int in_text(int a[]);
int pop_stack(int a[]);
int push_stack(int val, int a[], int len);
int get_error(int a[]);
void print_error(int error_code, int line);
//void print_stack(int a[]);

int stack_top, escaped;

int main(void) {
    int stack[N_SYMBOLS];
    int c, line, error;
    extern int stack_top;
    extern int escaped; 
    c = stack_top = line = error = escaped = 0;
    initialise_array(stack, N_SYMBOLS, 0);

    while ((c = getchar())!= EOF && !error) {
        error = check_error(c, stack, N_SYMBOLS);
        if (!error && c == '\n') ++line; 
    }
    //print_stack(stack);
    //printf("Error code is: %d", error);
    if (!error) {
        if (stack_top != 0) {
            error = get_error(stack);
        }
    }
    print_error(error, line);
    return 0;
}

void initialise_array(int a[], int len, int val)
{
    for (int i = 0; i < len; i++) a[i] = val;
}

int check_error(int c, int a[], int len)
{
    int error = 0;
    int txt_status = 0;
    extern int escaped;

    //check if we're in a text element
    if (!((txt_status = in_text(a)) == NOT_IN_TEXT)) {
        //printf("We're in text\n");
        if (c == '\\' && !escaped) escaped = ESCAPED;
        else if (txt_status == IN_CHAR && !escaped) {
            if (c == '\'') pop_stack(a);
        }
        else if (txt_status == IN_STR && !escaped) {
            if (c == '\"') pop_stack(a);
        }
        else if (escaped) escaped = NOT_ESCAPED;
    }
    //not in text -> check left braces
    else if  (c == '(' || c == '[' || c == '{') {
        error = push_stack(c, a, len);
    }
    //not in text -> check right braces
    else if (c == ')' || c == ']' || c == '}') {
        error = check_compatible(c, a);
        if (!error) pop_stack(a);
    }
    //not in text -> check if we start text
    else if (c == '\'' || c == '\"') {
        error = push_stack(c, a, len);
    }
    return error;
}

int check_compatible(int c, int a[])
{
    extern int stack_top;
    int return_value = 0;
    if (c == '}' && a[stack_top-1] != '{') return_value = UNBALANCED_BRACES;
    else if (c == ']' && a[stack_top-1] != '[') return_value = UNBALANCED_BRACKETS;
    else if (c == ')' && a[stack_top-1] != '(') return_value = UNBALANCED_PARENTHESES;
    return return_value;
}

int in_text(int a[])
{
    extern int stack_top;
    int return_status = 0;
    if (stack_top) {
        if (a[stack_top - 1] == '\"') {return_status = IN_STR;}
        else if (a[stack_top - 1] == '\'') {return_status = IN_CHAR;}
    }
    return return_status;
}

int pop_stack(int a[])
{
    extern int stack_top;
    int return_status = 1;
    if (stack_top) {
        a[stack_top - 1] = 0;
        return_status = 0;
    }
    --stack_top;
    return return_status;
}

int push_stack(int val, int a[], int len) 
{
    extern int stack_top;
    int return_status = 0;
    
    if (stack_top >= len) return_status = STACK_OVERFLOW;
    else {
        a[stack_top] = val;
    }
    ++stack_top;
    return return_status;
}

int get_error(int a[])
{
    extern int stack_top;
    int error = 0;
    int c = a[stack_top - 1];

    if (c == '{') error = UNBALANCED_BRACES;
    else if (c == '[') error = UNBALANCED_BRACKETS;
    else if (c == '(') error = UNBALANCED_PARENTHESES;
    else if (c == '\'') error = MISSING_SINGE_QUOTE;
    else if (c == '\"') error = MISSING_DOUBLE_QUOTE;
    return error;
}

void print_error(int error_code, int line)
{
    if (!error_code) {
        printf("Syntactic analysis complete, no errors found\n");
    }
    else if (error_code == UNBALANCED_BRACES) {
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

/*void print_stack(int a[])
{
    extern int stack_top;
    int i;
    for (i = 0; i < stack_top; i++) printf("[%c]", a[i]);
}*/
