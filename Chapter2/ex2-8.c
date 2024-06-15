/*
Chapter 2, Exercise 8
the function rightrot(x, n) returns x, with the bits
rotated right by n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_DIGIT 4
#define RIGHT 0
#define LEFT 1

unsigned int rightrot(unsigned int x, int n);
unsigned int wordLength();
int getLine(char s[], int lim);
int getNumber(char a[], int lim);

int main(void)
{
    char xs[MAX_DIGIT], ns[MAX_DIGIT];
    unsigned int x, n;
    printf("Enter x and n seperated by newlines\n");

    x = getNumber(xs, MAX_DIGIT);
    n = getNumber(ns, MAX_DIGIT);

    printf("x: %u, rotated x: %u\n", x, rightrot(x, n));
    return 0;

}

unsigned int rightrot(unsigned int x, int n) {
    unsigned int right_or_left = RIGHT;
    unsigned int rotbits;
    unsigned int wordlength = wordLength();

    if (n < 0) {n *= -1; right_or_left = LEFT;}
    
    if ((n = n % wordlength) > 0)
    {
        if (right_or_left == RIGHT) {
            rotbits = x & ~(~0 << n);
            rotbits = rotbits << (wordlength - n);
            x = x >> n;
        }
        else {
            rotbits = x & ~(~0u >> n);
            rotbits = rotbits >> (wordlength - n);
            x = x << n; 
        }
        x = x | rotbits;
    }
    return x;
}

unsigned int wordLength() {
    int i;
    unsigned int v = ~0;

    for (i = 1; (v = (v << 1)) > 0; i++);
    return i;
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

int getNumber(char a[], int lim)
{
    getLine(a, lim);
    return atoi(a);
}