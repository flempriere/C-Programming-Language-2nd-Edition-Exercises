/*
Chapter 2, Exercise 6: setbits(x,p,n,y) returns x with
the n digit subword beginning at p set to the rightmost
n digits of y.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGIT 3

int getNumber(char a[], int lim);
int getLine(char a[], int lim);

unsigned int getbits(unsigned int x, int p, int n);
unsigned int setbits(unsigned int x, int p, int n,
    unsigned int y);

int main(void) {
    char xs[MAX_DIGIT], ys[MAX_DIGIT], ps[MAX_DIGIT], ns[MAX_DIGIT];
    int x, y, p, n;
    printf("Enter x, y, p, n seperated by newlines\n");
    x = getNumber(xs, MAX_DIGIT);
    y = getNumber(ys, MAX_DIGIT);
    p = getNumber(ps, MAX_DIGIT);
    n = getNumber(ns, MAX_DIGIT);

    printf("Masked number is: %d\n", setbits(x, p, n, y));
    return 0;
}

int getNumber(char a[], int lim)
{
    getLine(a, lim);
    return atoi(a);
}

unsigned int getbits(unsigned int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned int setbits(unsigned int x, int p, int n,
    unsigned int y)
{
    return (x & ~(~(~0 << n) << (p + 1 - n))) |
        (y & ~(~0 << n)) << (p + 1 - n);

}

int getLine(char s[], int lim)
{
    /*for simplicity of example this getline will strip
    the newline, since it makes presenting the problem
    cleaner */ 
    int i, c = 0;
    for (i = 0; i < lim - 1 &&
        (c = getchar()) != EOF && c != '\n';) s[i++] = c;
    s[i] = '\0';
    return i;
}
