/*
- Exercise 3-4: Explain why the provided itoa fails for 
a maximally negative number in a two's complement 
representation, fix the function to work independent 
of representation.

Explanation: two's complement: max negative int is
1[000...000] and can go up to 1[111...111]
i.e 2^[word_size - 1], but positive 0[000...0000]
represents 0, so can only get up to 2^[word_size - 1] - 1.

Hence multiplying n -> -n for the largest negative causes
an overflow.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10

int getLine(char s[], int lim);
void itoa(int n, char s[]);
int abs(int x);
void reverse(char s[]);

int main()
{
    char input_s[MAX_LENGTH], output_s[MAX_LENGTH];
    printf("enter input string on length <= %d: ", MAX_LENGTH);
    getLine(input_s, MAX_LENGTH);

    int n = atoi(input_s);
    itoa(n, output_s);
    
    printf("Input string: %s\n", input_s);
    printf("Number is: %d\n", n);
    printf("Output string: %s\n", output_s);

}

void itoa(int n, char s[])
{
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
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
