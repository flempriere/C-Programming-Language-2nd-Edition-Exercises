/*
- Exercise 3-6: itoa(n, s, w) acts like itoa(n, s)
but if s is less than w char's wide it is padded to a
width of w.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10
#define BLANK 'b'

int getLine(char s[], int lim);
void itoa(int n, char s[], int w);
int abs(int x);
void reverse(char s[]);

int main()
{
    char input_s[MAX_LENGTH], output_s[MAX_LENGTH], min_width[MAX_LENGTH];
    printf("enter input string on length <= %d: ", MAX_LENGTH);
    getLine(input_s, MAX_LENGTH);
    printf("enter min_width < %d: ", MAX_LENGTH);
    getLine(min_width, MAX_LENGTH);

    int n, w;
    n = atoi(input_s);
    w = atoi(min_width);
    itoa(n, output_s, w);

    
    
    printf("Input string: %s\n", input_s);
    printf("Number is: %d\n", n);
    printf("Output string: %s\n", output_s);

}

void itoa(int n, char s[], int w)
{
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0) s[i++] = '-';
    while (i < w) {
        s[i++] = BLANK; // [using b for visibility of test]
    }
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
