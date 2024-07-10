#define NUMBER '0'
/* exercise 4-4 function keys*/
#define TOP '?'
#define DUPLICATE '~'
#define SWAP '@'
#define CLEAR '#'
#define VARIABLE_ASSIGNMENT '='
/* exercise 4-5 defines*/
#define MATH_FUNC '$'
#define LAST_PRINTED_VAR 'p'


/*Math functions*/
void mathfn(char s[], int lim);
void printRangeError(char s[], double x, double lower, double upper);

/* getch family */
int getch(void);
void ungetch(int c);

/*getop function*/
int getop(char s[]);

/*stack functions*/
void push(double f);
double pop(void);
double top(void);
void duplicate(void);
void swapTop(void);
void clear(void);