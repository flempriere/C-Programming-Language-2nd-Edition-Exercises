/*
Chapter 2, Exercise 7: invert(x, p, n) performs a bit flip 
on the n-digit subword of x starting at p.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGIT 4

unsigned int invert(unsigned int x, unsigned int p, 
    unsigned int n);
int getLine(char s[], int lim);
int getNumber(char a[], int lim); 

int main(void)
{
    char xs[MAX_DIGIT], ps[MAX_DIGIT], ns[MAX_DIGIT];
    unsigned int x, p, n;
    printf("Enter x, p, n followed by newlines: \n");
    x = getNumber(xs, MAX_DIGIT);
    p = getNumber(ps, MAX_DIGIT);
    n = getNumber(ns, MAX_DIGIT);
    printf("x: %x, inverted x: %x\n", x, invert(x, p, n));

    return 0;
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{   
    return x ^ (~(~0 << n) << (p - n + 1));
}

/*
x ^ [1111] etc. ->  if bit is 0 -> 1, if bit is 1 -> 0
x ^ [0000] etc. -> if bit is 0 -> 0, if bit is 1 -> 1.
*/

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

int getNumber(char a[], int lim)
{
    getLine(a, lim);
    return atoi(a);
}

