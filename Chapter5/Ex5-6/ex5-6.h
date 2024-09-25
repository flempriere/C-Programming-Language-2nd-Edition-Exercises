#define MAXLINE 100

/*get line implementation */
int getLine(char *s, unsigned int lim);

/* string to number conversions and viceversa */
int atoi(char *s);
void itoa(int n, char *s);
void itob(int n, char *s, unsigned int b);
void itoa2(int n, char *s, unsigned int w);
double atof(char *s);

/* string functions */
void reverse(char *s);
int strindex(char *s, char *t);
int strrindex(char *s, char *t);

