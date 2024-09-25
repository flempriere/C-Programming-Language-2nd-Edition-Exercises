#include <stdio.h>
#include <string.h>
#include "ex5-7.h"

int getLine(char s[], int lim)
{
    int i, c='\0';
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n');
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], char *arena, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *arena_end = arena + MAXLEN * MAXLINES;

    nlines = 0; 
    while((len = getLine(line, MAXLEN)) > 0 )
    {
        if (nlines >= maxlines || arena + len > arena_end) return -1;
        else
        {
            strcpy(arena, line);
            lineptr[nlines++] = arena;
            arena += (len + 1);
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0) printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    /* do nothing if nelems < 2*/
    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0) swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}