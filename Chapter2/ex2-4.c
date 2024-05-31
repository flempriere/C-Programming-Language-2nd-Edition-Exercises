/* 
Squeeze(s1, s2) deletes any character in s_1 that 
appears in s_2
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000
#define N_ASCII_CHAR 128
#define SEEN 1
#define NOT_LETTER -1

void init_array(int a[], int len, int val);
void squeeze(char s1[], char s2[]);
void squeeze_char(char s[], int c);
int getLine(char s[], int lim);

int main(void)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Enter s1: ");
    getLine(s1, MAXLINE);
    printf("s1: %s\n", s1);
    printf("Enter s2: ");
    getLine(s2, MAXLINE);
    printf("s2: %s\n", s2);
    squeeze(s1, s2);
    printf("Squeezed s1: %s\n", s1);
}

void init_array(int a[], int len, int val)
{
    for (; len > 0; --len) a[len -1] = val;
    return;
}

void squeeze(char s1[], char s2[])
/*
squeeze: squeezes out characters in s2 from s1,
we use an array to track characters we've already
seen
*/
{
    int i;
    int char_set[N_ASCII_CHAR];
    init_array(char_set, N_ASCII_CHAR, 0);
    for (i = 0; s2[i] != '\0'; ++i)
    {
        if (!char_set[(int) s2[i]]) {
            squeeze_char(s1, s2[i]); 
            char_set[(int) s2[i]] = SEEN;
        }
    }
}

void squeeze_char(char s[], int c)
/*
squeeze implementation from the book, working on a
char
*/
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c) s[j++] = s[i];
    }
    s[j] = '\0';
    return;
}

int getLine(char s[], int lim)
{
    int i, c;
    c = '\0';
    for (i = 0; (i < lim - 1) &&
        (c = getchar()) != EOF && c != '\n';) {
            s[i++] = c;
    }
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}
