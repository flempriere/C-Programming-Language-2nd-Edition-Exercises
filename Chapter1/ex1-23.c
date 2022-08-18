/* program that removes comments from a C file */

#include <stdio.h>

#define MULTILINE_COMMENT 4
#define SINGLELINE_COMMENT 3
#define IN_STRING 2
#define IN_CHAR 1
#define NORMAL 0


int main(void) {
    int saw_slash, saw_star, c;

    int in_comment = 0;
    saw_slash = 0;
    saw_star = 0;

    while ((c = getchar()) != EOF) {
        if (in_comment == NORMAL) {
            if (c == '/') {
                if (saw_slash) {in_comment = SINGLELINE_COMMENT; saw_slash = 0;}
                else saw_slash = 1;
            }
            else if (c == '*') {
                if (saw_slash) {in_comment = MULTILINE_COMMENT; saw_slash = 0;}
                else putchar(c);
            }
            else if (c == '\"') {
                in_comment = IN_STRING;
                if (saw_slash) {putchar('/'); saw_slash = 0;}
                putchar(c);
            }
            else if (c == '\'') {
                in_comment = IN_CHAR;
                if (saw_slash) {putchar('/'); saw_slash = 0;}
                putchar(c);
            }
            else {
                if (saw_slash) {putchar('/'); saw_slash = 0;}
                putchar(c);
            }   
        }
        else if (in_comment == IN_CHAR) {
            if (c == '\'') {in_comment = NORMAL; putchar(c);}
            else {putchar(c);}
        }
        else if (in_comment == IN_STRING) {
            if (c == '\"') {in_comment = NORMAL; putchar(c);}
            else {putchar(c);}
        }
        else if (in_comment == SINGLELINE_COMMENT) {
            if (c == '\n') {in_comment = NORMAL; putchar(c);}
        }
        else if (in_comment == MULTILINE_COMMENT) {
            if (c == '*') {
                saw_star = 1;
            }
            else if (c == '/') {
                if (saw_star) {in_comment = NORMAL; saw_star = 0;}
            }
            else {
                if (saw_star) {saw_star = 0;}
            }
        }
    }
    return 0;
}