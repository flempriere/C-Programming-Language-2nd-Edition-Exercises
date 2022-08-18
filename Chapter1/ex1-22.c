/*
Exercise 1-22 "Fold": A program that folds long input lines into two or more
shorter lines after the last non blank character that occurs before the n-th
column of input.

Note as written if you have a line 'abc efg'  where the split column is '5',
then the split should be 'abc e\nfg'
*/

#include <stdio.h>

#define TABINC 8
#define MAX_COL 80

void print_line(char line[], int len);
int detab(char line[], int len, int index);

int main(void) {
    
    int c, i;
    char split_line[MAX_COL];

    i = 0;
    
    while ((c = getchar()) != EOF) {
        split_line[i] = c;
        ++i;

        if (c == '\t') i = detab(split_line, TABINC, i);
        else if (c == '\n' || i >= MAX_COL) {
            print_line(split_line, i);
            i = 0;
        }
    }
}

void print_line(char line[], int len) {
    int find_non_blank = 1;
    int j = len - 1;
    while (find_non_blank) {
        if (line[j] == ' ' || line[j] == '\n') --j;
        else find_non_blank = 0;
    }
    if (j >= 0) {
        len = j + 1;
        for (j = 0; j < len; j++) putchar(line[j]);
        putchar('\n');
    }
}

int detab(char line[], int len, int index) {
    int n_spaces = 0;

    n_spaces = TABINC - ((index - 1) % TABINC);

    for (int j = n_spaces; j > 0 && index - 1 < MAX_COL; --j) {
        line[index - 1] = ' ';
        ++index;
    }
    if (index >= MAX_COL) {print_line(line, MAX_COL); index = 0;}
    return index;
}