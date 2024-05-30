/*
Gives an equivalent loop expression to
for (i < lim - 1; 
    (c = getchar()) != EOF and c != '\n';
    ++i)
without the use of logic operators
*/

#include <stdio.h>

#define LIM 1000
#define TRUE 1
#define FALSE 0

int getLine(char line[]);
void printLine(char line[], int len);

int main(void)
{
    char line[LIM];

    int len = getLine(line);
    printLine(line, len);
    
    return 0;
}

int getLine(char line[])
{
    int i = 0;
    char c;
    int read_flag = TRUE;
    
    while (read_flag)
    {
        if (i < LIM - 1)
        {
            c = getchar();
            if (c != EOF)
            {
                if (c != '\n') {
                    line[i] = c;
                    ++i;
                }
                else {
                    read_flag = FALSE;
                }
            }
            else {
                read_flag = FALSE;
            }
        }
        else read_flag = FALSE;
    }
    line[i] = '\0';
    return i;
}

void printLine(char line[], int len)
{
    int i = 0;
    for (i = 0; i < len; ++i) putchar(line[i]);
}
