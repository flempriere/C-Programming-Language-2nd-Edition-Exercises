/*
- Exercise 3-5: aitoa(n, s, b) implementation, will use
convert integer n to a string representation s in base b.
For bases b > 10, alphabetic characters are used.

We impose an upper limit of 36 since then we run out of
alphabetic digits.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10
#define MAX_BASE 36

int getLine(char s[], int lim);
void itoa(int n, char s[], int b);
int abs(int x);
void reverse(char s[]);

int main()
{
    char input_s[MAX_LENGTH], output_s[MAX_LENGTH], base[MAX_LENGTH];
    printf("enter input string on length <= %d: ", MAX_LENGTH);
    getLine(input_s, MAX_LENGTH);
    printf("enter base (2 - %d): ", MAX_BASE);
    getLine(base, MAX_LENGTH);

    int n;
    int b;
    n = atoi(input_s);
    b = atoi(base);

    if (b > 36 || b < 1) printf("invalid base!\n");
    else {
        itoa(n, output_s, b);
        printf("Input string: %s\n", input_s);
        printf("Number is: %d\n", n);
        printf("Output string: %s\n", output_s);
    }
    return 0;
}

void itoa(int n, char s[], int b)
{
    int i,v, sign;
    sign = n;
    i = 0;
    do {
        v = abs(n % b);
        s[i++] = v + ((v < 10) ? '0' : ('A' - 10));
    } while ((n /= b) != 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int abs(int x)
{
    return (x < 0) ? -x : x;
}

void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int getLine(char s[], int lim)
/* For simplicity we clip newlines*/
{
    int i, c = 0;
    for (i = 0; i < lim - 1 &&
        (c = getchar()) != EOF && c != '\n';) s[i++] = c;
    s[i] = '\0';
    return i;
}
