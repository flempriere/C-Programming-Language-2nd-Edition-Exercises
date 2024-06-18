/*
escape(s, t) copies t to s, replacing escapes with their escape
character is a visible way and reversed.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);
int getLine(char s[], int lim);


int main()
{
    char s[MAX_LENGTH], t[MAX_LENGTH], u[MAX_LENGTH];
    getLine(t, MAX_LENGTH); //read into t
    escape(s, t); //copy t into s
    unescape(u, s); //copy s into u

    printf("Original string: %s\n", t);
    printf("Escaped string: %s\n", s);
    printf("Unescaped string: %s\n", u);

}

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0' && i < (MAX_LENGTH - 1); i++)
    {
        switch(t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0' && i < (MAX_LENGTH - 1); i++) {
        switch(t[i])
        {
        case '\\':
            switch(t[++i])
            {
            case 't':
                s[j++] = '\t';
                break;
            case 'n':
                s[j++] = '\n';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}


int getLine(char s[], int lim)
{
    int i, c = 0;
    for (i = 0; i < lim - 1 &&
        (c = getchar()) != EOF && c != '\n';) s[i++] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
