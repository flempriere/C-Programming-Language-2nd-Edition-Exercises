/*
Exercise 2-9:
Implementation of a faster bitcount for two's complement

Two's complement:
- highest bit represents sign
- positive numbers represented as 0[number]
- negative number represented as 1[~abs(number)]

x - 1 -> x + (-1) 
has repr
    xxxx 1000   explicit 
+   1111 1111
    ---------
    xxxx 0111

Since x + '1' + '1' = x + '0' (with carry propagating) = x
*/
#include <stdlib.h>
#include <stdio.h>

#define MAX_DIGIT 4

int fastbitcount(unsigned int x);
int getLine(char s[], int lim);
int getNumber(char a[], int lim);

int main()
{
    char xs[MAX_DIGIT];
    unsigned int x;
    printf("Enter x\n");

    x = getNumber(xs, MAX_DIGIT);

    printf("n bits in x = %d: %d\n", x, fastbitcount(x));
    return 0;
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

int fastbitcount(unsigned int x)
{
    int b;
    for (b = 0; x != 0; x &= x - 1) b++;
    return b;
}
