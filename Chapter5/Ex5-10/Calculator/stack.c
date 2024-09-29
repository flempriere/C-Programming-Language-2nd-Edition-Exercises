#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0; 
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0) return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
/*
Exercise 4-4 functions
top: returns the top element without popping
duplicate: duplicates the top element
swapTop: swaps the top two elements

Note: These functions could be implemented in an
implementation-free way using push() and pop()
but we take advantage of the array implementation
to do less operations.
*/
double top(void)
{
    if (sp > 0) return val[sp - 1];
    printf("error: stack empty\n");
    return 0.0;
}

void duplicate(void)
{
    if ((sp > 0) && (sp < MAXVAL)) push(top());
    else {
        printf("error: stack empty\n");
    }
}

void swapTop(void)
{
    if (sp < 2) {
        printf("error: not enough elements to swap\n");
    }
    else {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
}

void clear(void)
{
    sp = 0;
}