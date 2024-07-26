# The C Programming Language
## Chapter 5: Pointers and Arrays


### Summary of Exercises

### Introduction
- A pointer is a variable that contains the address of another variable
- Pointers are closely related to arrays

### Pointers and Addresses
- Memory consists of individual cells
    - they may be manipulated individually
    - or, as a contiguous group

- Pointer is a block of memory containing the address of another block of memory

- The `&` operator gives the address of an object, so `p = &c` assigns the address of `c` to `p`.
    - `&` only applies to memory objects
    - Cannot be used on expressions, constants or `register` variables

- The `*` operator is called the *indirection* or *dereferencing* operator
    - Applied to a pointer it accesses the object at the address pointed to by the pointer.

**Example: Use of a pointer**
```
int x = 1, y = 2, z[10];
int *ip; /* ip is a pointer to an int */

ip = &x /* ip points to x */
y = *ip; /* y is now 1  --- equiv to y = x*/ 
*ip = 0; /* x is now 0 */
ip &z[0]; /* ip now points to z[0] */
```

- The declaration of the pointer `int *ip;` is a mnemonic, it states
that `*ip` is an int. 
    - The logic also applies to function declarations, e.g. `double *dp, atof(char *);`
        - states `*dp` and `atof` have values of `double`, and the argument of `atof` is a pointer to `char`.
- pointer is constrained to  point to a given kind of object.
    - **exception** a pointer to `void` may hold any pointer, but cannot be *dereferenced*.

- if `ip` points to the integer `x`, then `x` can be substituted by `*ip` in any context.

```
*ip = *ip + 10; /* equiv to: */
x = x + 10;
```
- Unary operators `*` and `&` bind more tightly than arithmetic operators.
```
y = *ip + 1
```
Takes `ip`, dereferences it, adds `1`, assigns to `y`.
```
*ip += 1
```
Increments what `ip` points to, as do
- `++*ip`
- `(*ip)++`
    - Needs parentheses (else `ip` itself is incremented)
        - Because `*` and `++` associate right to left. (i.e. `*` associates to `(ip++)`)
- Pointers can be used without derefencing
    - They are still variables
    - e.g. if `ip` and `iq` are pointer to `int`, `ip = iq` copies the value (i.e. address in) of `iq` to `ip`.
        - Hence `ip` now points to the same object as `iq`.

### Pointers and Function Arguments
- *Recall:* C passes function arguments by *value*
    - function cannot directly modify value of the original argument,  it modifies a copy.
- We can use pointers to the *values* we want to change instead.

**Example: swap**

```
/*Broken Swap
**This version doesn't work since it operates on copies
*/
void swap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

/*fixed Swap
**This version uses pointers to swap values
void swap(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int a, b;
/* assign values ... to a, b */
swap(&a, &b);
```
- The first version doesn't work because the arguments are copies
- In the second the function operates on the pointers, we pass the addresses of the variables to swap with `&`.

- Pointer args allow a function  to access and change objects in the function that calls them.
    - e.g. consider a function `getint` that converts an input character stream into integers.
        - Has to return the found integer **and** signal when the input has finished, i.e. `EOF`.
            - Since `EOF` may correspond to a valid integer these have to be via different paths.

**Example : getint**
```
int n, array[SIZE], getint(int *);

for (n = 0; n < SIZE && getint(&array[n]) != EOF;  n++);

#include <ctype.h>

int getch(void);
void ungetch(void);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while(isspace(c = getch())); /*skip whitespace */

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') c = getch();
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c = '0');
    }
    *pn *= sign;
    if (c != EOF) ungetch(c);
    return c;
}
```
- This calls `getint()` for every index in the array
- `*pn` is used in `getint` as a ordinary `int`
- `getch()` and `ungetch()` are the same as for the calculator


