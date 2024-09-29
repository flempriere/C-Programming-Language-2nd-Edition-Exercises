#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#define PI 3.1415

void mathfn(char s[], int lim)
/*
We use strncmp, since strcmp(s, t) = 0 if equal we have
to use note operator ! to invert truthfulness
*/
{
    double x, y;
    if (!strncmp(s, "sin", lim)) push(sin(pop()));
    else if (!strncmp(s, "cos", lim)) push(cos(pop()));
    else if (!strncmp(s, "tan", lim)) push(tan(pop()));
    else if (!strncmp(s, "asin", lim)) {
        x = pop();
        if (!((x < 1) && (x > - 1)))
        {
            printRangeError("asin", x, -1, 1);
        }
        else push(asin(x));
    }
    else if (!strncmp(s, "acos", lim)) {
        x = pop();
        if (!((x < 1) && (x > -1)))
        {
            printRangeError("acos", x, -1, 1);
        }
        else push(acos(x));
    }
    else if (!strncmp(s, "atan", lim)) push(atan(pop()));
    else if (!strncmp(s, "atan2", lim)) {
        x = pop();
        if (x != 0.0) push(atan2(pop(), x));
        else printf("Error: zero divisor in function atan2");
    }
    else if (!strncmp(s, "sinh", lim)) push(sinh(pop()));
    else if (!strncmp(s, "cosh", lim)) push(cosh(pop()));
    else if (!strncmp(s, "tanh", lim)) push(tanh(pop()));
    else if (!strncmp(s, "exp", lim)) push(exp(pop()));
    else if (!strncmp(s, "log", lim)) push(log(pop()));
    else if (!strncmp(s, "log10", lim)) push(log10(pop()));
    else if (!strncmp(s, "pow", lim)) {
        y = pop();
        push(pow(pop(), y));
    }
    else if (!strncmp(s, "sqrt", lim)) {
        x = pop();
        if (x < 0) printf("error: argument of sqrt must be non-negative\n");
        else push(sqrt(x));
    }
    else if (!strncmp(s, "ceil", lim)) push(ceil(pop()));
    else if (!strncmp(s, "floor", lim)) push(floor(pop()));
    else {
        printf("error: unrecognised function\n");
    }
}

void printRangeError(char s[], double x, double lower, double upper)
{
    printf("error: value of x %g is invalid for %s.\n", x, s);
    printf("Valid range is [%g, %g]\n", lower, upper);
}