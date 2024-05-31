/*
any(s1, s2) returns the index of the first occurence of
a char c in s_1 that also occurs in s_2
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000
#define N_ASCII_SYM 128
#define SEEN 1
#define NO_MATCH -1

int any(int s1[], int s2[]); 
void init_array(int a[], int len, int val);
int getLine(int s[], int lim);
void tag_chars_in_string(int a[], int s[]);

int main(void)
{
    int s1[MAXLINE];
    int s2[MAXLINE];

    printf("Enter s1: ");
    getLine(s1, MAXLINE);
    printf("Enter s2: ");
    getLine(s2, MAXLINE);
    int index = any(s1, s2);
    if ((index != NO_MATCH)) {
        printf("Match found at %d, match is %c\n",
            index, s1[index]);
    }
    else printf("No match found\n");

    return 0;
}

int any(int s1[], int s2[])
{
    int char_set[N_ASCII_SYM], i;
    tag_chars_in_string(char_set, s2);
    for (i = 0; s1[i] != '\0' && 
        !(char_set[s1[i]] == SEEN); i++);
    if (s1[i] == '\0') i = NO_MATCH;
    return i;
}

void init_array(int a[], int len, int val)
{
    for (; len > 0; --len) a[len - 1] = val;
    return;
}

int getLine(int s[], int lim)
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

void tag_chars_in_string(int a[], int s[])
{
    int c;
    for (c = 0; s[c] != '\0';) a[s[c++]] = SEEN;
    return;
}
