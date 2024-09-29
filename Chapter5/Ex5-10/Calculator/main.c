/*
main file for the calculator program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100


#define N_VARIABLES 27 //alphabetic variable support + last accessed

void initialiseArray(double a[], int len);


int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("error: call structure is eval expression");
        return 1;
    }
    int type, var;
    var = 0;
    double op2;
    char s[MAXOP];
    double variables[N_VARIABLES];
    initialiseArray(variables, N_VARIABLES);
    set_input(argc - 1, argv + 1);
    while((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case MATH_FUNC:
            mathfn(s, MAXOP);
            break;
        case TOP:
            variables[N_VARIABLES - 1] = top();
            printf("\t%.8g\n", variables[N_VARIABLES - 1]);
            break;
        case DUPLICATE:
            duplicate();
            break;
        case SWAP:
            swapTop();
            break;
        case CLEAR:
            clear();
            break;
        case VARIABLE_ASSIGNMENT:
            pop(); //remove previous variable assignment
            if (isupper(var)) variables[var - 'A'] = pop();
            else printf("error: invalid variable name\n");
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop()/op2);
            else printf("error: zero divisor!\n");
            break;
        case '%':
            /*Ex 4-3: We handle float values by using fmod*/
            op2 = pop();
            if (op2 != 0.0) push(fmod(pop(), op2));
            break;
        case '\n':
            variables[N_VARIABLES - 1] = pop();
            printf("\t%.8g\n", variables[N_VARIABLES - 1]);
            break;
        default:
            if (isupper(type)) push(variables[type - 'A']);
            else if (type == LAST_PRINTED_VAR) push(variables[N_VARIABLES - 1]);
            else {
                printf("error: unknown command %s\n", s);
            }
            break;
        }
        var = type;
    }
    variables[N_VARIABLES - 1] = pop();
    printf("\t%.8g\n", variables[N_VARIABLES - 1]);
    printf("\n");
    return 0;
}
void initialiseArray(double a[], int len)
{
    for (; len > 0; len--) a[len - 1] = 0.0;
    return;
}