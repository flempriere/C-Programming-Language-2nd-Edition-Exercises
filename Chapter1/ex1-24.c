/*Peforms basic syntax analysis

As a simpliyfing assumption we assume that
there are no comments (these can be removed
via running ex1-23 on the source first) */

/*Need to check for
- unbalanced parantheses, etc
- missing double/single quotes
- interleaved parantheses etc*/

#include <stdio.h>

#define N_SYMBOLS 5

#define UNBAL_PARENTHESES 1
#define UNBAL_BRACES 2
#define UNBAL_BRAKETS 3
#define UNBAL_QUOTE 4
#define UNBAL_DBL_QUOTE 5

#define NOT_FOUND -1
#define FOUND 1


void initialise_array(int a[], int len, int val);
int check_error(int c, int a[], int len);

int main(void) {
    int last_syntax_position[N_SYMBOLS];
    int c, line, error = 0;
    initialise_array(last_syntax_position, N_SYMBOLS, NOT_FOUND);

    while ((c = getchar()) != EOF && !error) {
        error = check_error(c, last_syntax_position, N_SYMBOLS);
        if (!error && c == '\n') ++line;
    }
}

void initialise_array(int a[], int len, int val)
{
    for (int i = 0; i < len; i++) a[i] = val;
}

int check_error(int c, int a[], int len)
{
    int err = 0;
    //first check if in a string or char
    if (a[UNBAL_QUOTE]) {
        if (c == '\'') a[UNBAL_QUOTE] = NOT_FOUND;
    }
    else if (a[UNBAL_DBL_QUOTE]) {
        if (c == '\"') a[UNBAL_DBL_QUOTE] = NOT_FOUND;
    }
    //now check if we have errors
    
}
