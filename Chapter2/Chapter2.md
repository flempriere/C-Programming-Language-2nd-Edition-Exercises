# The C Programming Language
## Chapter 2: Types, Operators and Expressions

### Summary of Exercises
- Exercise 2-1: Determines the range of ints, chars,
shorts, longs and long longs (including unsigned) by reference to `limits.h` and float and double through `float.h`.
- Exercise 2-2: Converts the expression `for (i < lim - 1; (c = getchar()) != EOF && c != '\n'; ++i);` to a loop without logic operators.
- Exercise 2-3: Converts a string representation of hexadecimal number to the corresponding decimal integer.
- Exercise 2-4: Squeeze(s1, s2), deletes each character in
$s_1$ that occurs in $s_2$.
- Exercise 2-5: `any(s1, s2)` returns the index of the first character in $s_1$ that is also in $s_2$. 
- Exercise 2-6: `setbits(x, p, n, y)` sets the word of length $n$
starting at $p$ in $x$ to the rightmost $n$ bits of $y$.
- Exercise 2-7: `invert(x, p, n)` returns $x$ with the word of length $n$ starting at $p$ bit-flipped.
- Exercise 2-8: `rightrot(x, n)` rotates the bits in `x` to the right by `n`.
- Exercise 2-9: Two's complement implementation of `bitcount(x)`.
- Exercise 2-10: Implementation of `lower(s)` using a conditional operator


### Introduction

- *Variables and Constants*: basic data objects, names, types and optionally initial values listed by *Declarations*
- *Operators* specify actions taken on data objects
- *Expressions* combine variables and constants to create new values

### Variable Names

- Names are made of letters and digits
    - first character must be a letter
    - _ may be used as a letter
        - avoid starting names with _ since this may conflict with library routines
    - Upper and lower case letters are distinct, e.g. `X` != `x`
    - Practice: use lower case for *variables* and upper case for *symbolic constants*
- At least first 31 characters of an internal name are significant.
    - may be less for function names and external variables
        - (Since these may be used by assemblers and loaders - language can't control them.)
        - For external names, uniqueness only guaranteed for 6 characters and a single case
- Keywords (e.g. `if, else, int, float`) are reserved
- Use variable names that are related and unlikely to get mixed up
    - short for local variables, longer for external variables

### Data Types and Sizes

There are limited C data types
- `char`: single byte (can hold one character in the local character set)
- `int`: integer, reflecting natural size of integer on the host machine
- `float`: single-precision floating point
- `double`: double-precision floating point

Qualifiers can be used to modify types
- e.g. `short` and `long` which may be applied to integers
    - `short` and `long` should provide different size ints
        - `short` is often 16 bits (2 bytes)
        - `long` is often 32 bits (4 bytes)
        - `int` is either 16 or 32 bits
    - Compiler choses the size but `shorts` and `ints` are at least 16 bits and `longs` at least 32 bits
    with a `short` to be no longer than an `int`, with `int` to be no longer than a `long`.
- e.g. `signed` and `unsigned` which may apply to `char` and `int`
    - unsigned types are non-negative and subject to modulo arithmetic of $2^n$ where $n$ is the number of bits.
    - signed ints typically use two's complement therefore a 16 bit `char` has a range from $-128$ to $127$.
    - plain `char` may be `signed` or `unsigned`, but all printable characters are positive.
- `long double` specifies extended floating point precision
    - implementation is machine dependent, `float`, `double`, `long double` may be one, two or three distinct types.

- the standard headers `<limits.h>` and `<float.h>` contain symbolic constants for these sizes and other
machine and compiler.

### Constants
- integer constant like `1234` is an `int`
- `long` constant written with terminal `l` or `L`
    - e.g. `123456789L`
    - constants too big for an `int` will also be a `long`
- `unsigned` constants are written with a terminal `u` or a `U` an can be combined with `long` as `ul` or `uL` etc.
- floating point constants contain a decimal point
(e.g. `1.2`) or an exponent (e.g. `1e-2`).
    - Assumed to be `double` unless suffixed with `f` or `F`. 
    - May also use `l` or `L` to denote a `long double`.
- numbers may be specified in octal or hexadecimal
    - leading `0` denotes octal leading `0x` or `0X` denotes hexadecimal
        -e.g. 31 (decimal) = 037 (octal) = 0x1F (hexadecimal)
    - may also be combined with other suffixes
        -e.g. `0xFUL` is an `unsigned long` with a value of 15 (decimal)
- A *character constant* is an integer constant written as a one character with single quotes e.g. `'x'`. The value is the the numeric value assigned to the character in the machine character set.
    - e.g. `'0' == 48 != 0`.
    - This allows characters to be written in a machine independent way
    -  characters may be be represented in character and string constants by escape sequences (e.g. newline `\n`.)
    - character constants participate in numerical operations like integers
- We can specify arbitrary *byte-sized bit patterns*
via `'\ooo'` where `o` is an octal digit or `'\xhh'` where `h` is a hexadecimal digit.
    - e.g.
      -  `#define VTAB '\013'` - ASCII vertical tab
      - `#define BELL '\007'` - ASCII bell symbol
    - or in hexadecimal
        - `#define VTAB '\xb'` - ASCII vertical tab
        - `#define BELL 'x7'` - ASCII bell symbol
- All escape sequences
    - `\a` alert
    - `\b` backspace
    - `\f` formfeed
    - `\n` newline
    - `\r` carriage return
    - `\t` horizontal tab
    - `\v` vertical tab
    - `\\` backslash
    - `\?` question mark
    - `\'` single quote
    - `\"` double quote
    - `\ooo` octal number
    - `\xhh` hexadecimal number
- The *character constant* `'\0'` is used to indicate the character with numerical value `0`.
    - also called the null

- A *constant expression* is an expression that contains only constants
    - Can be evaluated at compile time (and included whereever a constant would be)
    - e.g. `#define MAXLINE 1000`
    - `char line[MAXLINE + 1]`
    or
    - `#define LEAP 1`
    - `int days[31 + 28 + LEAP + etc]`. 

- A *string literal* or *string constant* is a sequence of 0+ characters surrounded by *double quotes*
    - e.g. `"string"`  or `""`
    - Note quotes not part of the string
    - string constants may concatenate at compile time e.g. `"string" "name"` -> `"string name"`.
    - Can split long strings across lines
    - string const is a null-terminated array, therefore space needs is $n + 1$ where $n$ is the number of characters in the string.
        - no restriction on string size
        - length must be scanned

- `strlen(s)` is a library function to do this for a string `s`. Example implementation is
`int strlen(char s[]) { int i; i = 0; while (s[i] != '\0') { ++i; } return i; }`
    - `strlen` and other functions for strings are defined in `string.h`. 

- Note: `'x'` is not the same as `"x"`.

- The last type of constant is the *enumeration constant*
    - A list of integer constants, as in
    - `enum boolean {NO, YES};`
    - first has a value of $0$, the second $1$ and so on etc.
        - can provide explicit values, then will be followed on sequentially
        - e.g. `enum escapes {BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r'};`
        - and `enum months {JAN = 1, FEB, MARCH, etc...}`.
        - names must be unique in an enumeration but not across all enumerations
        - enums associate constants with names like `define`, but can be checked, and potentially debugged symbolically

### Declarations
- Must declare variables before use, often with type
    - some declarations can be done implicitly
    - declaration structure is a type, followed by a list of variable names of that type
        - e.g. `int lower, upper, step;`
        - e.g. `char c, line[MAXLINE];`
- declarations may or may not be assigned with initialisations
    - e.g. `char esc = '\\'`
    - `int i = 0`
    - `int limit = MAXLINE + 1`
    - `double eps = 1.0e-5`
- For non-automatic variable, initialisation is done once, (prior to execution)
- initialiser must be a constant expression
- explicitly initialised automatic variable is initialised each time the function or block containing
    - initialiser may be any expression
- external or static variables are initialised to zero by default
- uninitialised automatic variables are undefined
- `const` may be applied to any variable
    - specifies it will not be changed
    - e.g. `const double e = 2.7182818`
    - e.g. `const char msg[] = "warning: "`
    - may also be used with functions containing array arguments to indicate the array is not changed
        - e.g. `int strlen(const char[]);`
    - result of attempting to change a `const` variable is implementation defined
### Arithmetic Operators
- binary arithmetic operators are
    - `+, -, *, /` and modulus `%`.
- Integer division truncates fractions
- modulus `%` returns the remainder of `x % y`
    - leap year expression is therefore:

`if ((year % 4 == 0 && year % 100 != 0) ||
    year % 400 == 0)
    printf("%d is a leap year\n", year);
else 
    printf("%d is not a leap year\n", year);`

- `%` operator not defined for floating point types
- truncation direction of `/` and sign of `%` for negative numbers is machine dependent
    - same for overflow and underflow
- precedence is (*unary* +, - ) > (*, /, %) > (*binary* +, -).
- Arithmetic operators associate left to right

### Relational and Logic Operators
- relational operators are >, >=, <, <=
    - all identical precedence
    - lower precedence than arithmetic
        - e.g. `i < lim - 1` => `i < (lim - 1) 
- equality operators ==, != have lower precedence
- logic operators && and ||.
    - (expr 1) *logic* (expr 2) etc. is evaluated left to right
    - stops once truthfulness established
- e.g. recall
`for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)`

The test `i < lim - 1` *must* be made first to ensure there is space for the character, and must stop if this test fails.

Then we need to assign the new char to `c` before we test it's value so `(c = getchar())` *must* occur before comparison

`&&` has higher precedence than `||`
    - both lower than relational + equality
    - so `(i < lim - 1) && (c = getchar()) != '\n' && c != EOF` does not need brackets

But `!=` has higher precedence than assignment,

- `c = getchar() != EOF`, compares `getchar()` to `EOF` and then assigns this to `c`.
- A true expression evalutes as `1` while false evaluates as `0`.

Unary negation operator `!` converts non-zero operand into 0 and a zero operand to 1. 
- e.g. `if (!valid)` <=> `if (valid == 0)`

### Type Conversions

- Operators acting on multiple types will convert them to a common type based on a small ruleset.
    - automatic conversions typically only *narrower* -> *wider*
        - e.g. `char` -> `int` -> `long`
    - Or integer to floating point in `f + i`.
- Expressions like subscripting a float don't make sense and are forbidden.
- Assignments which lose information, e.g. wider type to narrow (float -> int, int -> char) may cause a warning but are not forbidden.

#### Chars
- small int, therefore can be used numerically.
- enables simple character conversions.
- e.g. Naive `atoi()`
```
/* atoi: converts s to integer */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) 
    {
        n = 10 * n  + (s[i] - '0');
    }
    return n;
}
```
- `s[i] - '0'` gives the numeric value of the character stored in `s[i]`. 

- We also have the `lower()` function to convert a char c to lowercase
```
/*lower: convert c to lower case: ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c
}
```
But this only works for the ASCII (since the corresponding lower and upper case letters are a fixed numerical distance apart, and they are arranged contiguously)

This is not strictly true for other character sets, e.g. EBCDIC has other characters between letters and so would convert other symbols. 

- The standard header `<ctype.h>` provides an interface of functions for tests and conversions independent of character set. 
    - e.g. `tolower()` is a character set agnostic version of `lower()` described above.
    - and `c >= '0' && c <= '9'` can be replaced by `isdigit()`.

Need to be careful when converting char to int. Since chars can be signed or unsigned question of if a char can become a negative integer is open ended.
- machine dependent
    - some with a leftmost bit set to $1$ is converted to a negative integer (sign extension)
    - may instead be padded with `0` to an integer
    length.
- C definition ensures any valid char in the character set is converted to a non-negative integer.
    - arbitrary bit patterns may be positive or negative depending on the machine
        - specify `unsigned` or `signed` for portability

Relational expressions like `i > j` (or those connected by `||` and `&&` ) evaluate to $1$ if true else $0$.

- `d = c >= '0' && c <= '9'` assigns $d$ $1$ if $c$ is a digit else $0$.
- Note any non-zero value is treated as true, and this is often used by functions like `isdigit()` and tests for `if, while, for etc...`

#### Implicit conversions

Typically *lower* type is promoted to the *higher* type. For unsigned types the informal rules below apply
- If either operand `long double`, convert to `long double`.
- else if operand `double`, convert to `double`
- else if operand `float`, convert to `float`
- else convert `char` or `short` to `int`
- then if either operand `long` convert to `long`.

Note `float` is not implicitly converted to a `double`.
- math expressions like those in `<math.h>` use double precision
- `float` typically used to save storage (or time) where either is expensive.


Conversions are more expensive for unsigned types since comparisons are machine dependent (since they dependent on type sizes)
- e.g. if `int` is 16 bit with a 32 bit `long`.
    - `-1L < 1U` as `1U` is promoted to from an `unsigned int` to a `signed long`.
    - But, `-1L > 1UL` because `-1L` is promoted to an `unsigned long` and appears to be a large positive number

Conversions take place across assignments; right side value is converted to type on the left, which is the type of the result.

- chars convert to int according to machine dependent rules
- Longer integers convert to shorter ones or chars by dropping the higher order bits, thus
```
    int i;
    char c;

    i = c;
    c = i;
```
does not change `c`, however `c = i; i = c;` may lead to information loss.

If `x` is `float` and `i` is `int` then
`x = i` and `i = x` both cause conversions.
- `float` to `int` truncates the fractional part
- `double` to `float` either rounds or truncates dependeing on the implementation

- Type conversion also occurs during function calls, without a prototype, `char` and `short` -> `int`, `float` -> `double`. 

- Explicit conversion can be forced with the type conversion operator called a `cast`:
    - `(type name) expression`
    - conversion follows rules above
    - cast acts like assignment to variable of given type
    - e.g. `math.h` function `sqrt()` expects *double* argument, so can use cast for integer arguments
        - e.g. `sqrt((double) n)`.
    - cast expression is unchanged
    - same precedence as other unary operators
- function protoype will automatically coerce arguments.
    e.g. `sqrt` has prototype
        - `double sqrt(double n)`
    - the call
        - `root2 = sqrt(2)`
    coerces the integer 2 into the double 2.0
- The standard library contains a portable implementation of a pseudo-random number generator, and a seed initialisation function; the former casts,
```
unsigned long int next = 1;
/* rand: return pseudo-random number on 0..32767*/
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32767;    
}
/* srand: set seed for rand() */
void srand(unsigned int seed) 
{
    next = seed;
}
```

### Increment and Decrement Operators

- Two in(de)crment operators, `++` increases by one, `--` decreases by 1.
    - May be used pre or post fix.
    - `++n` increments *before* the value is used, `n++` increments *after* the value is used
        e.g. if $n = 5$, the `x = ++n` sets $x$ to 6, while `x = n++` sets $x$ to 5.
    - note expressions like `(i+j)++` is invalid, only works on variables
- While often equivalent, then may not be, consider `squeeze()` below

```
/* squeeze: delete all c from s */
void squeeze(char s[], char c)
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
        s[j] = '\0';
    }
}
```

Each time a non-$c$ occurs, it is copied into the $j$ position and then $j$ is incremented for the next character.

### Bitwise Operators

C provides six bitwise operators, typically they may only
be applied to integral operands.
- `&` bitwise AND
- `|` bitwise (inclusive) OR
- `^` bitwise (exclusive) OR
- `<<` leftshift
- `>>` rightshift
- `~` one's complement (unary) (bitwise NOT)

Bitwise AND is good for masking off bits
e.g.  `n & 0177` zeros all but the low-order $7$ bits on $n$
(why? 0177 is an octal representation i.e. $[001][111][111]$ when viewed as binary block)

Bitwise OR is good for setting bits
e.g. `x = x | SET_ON`
sets the bits in $x$ to $1$ if they are already set in $x$ or are set in `SET_ON`.

Bitwise XOR sets a one in each bit position where its operands have different bits and zero where they are the same.

Note, the logic operators `&&` and `||` are distinct from the bit operators `&` and `|`.
- e.g. if $x = 1 [01]$ and $y = 2 [10]$, then `x & y` is zero, but `x && y` is one.

- bitshift operators $x <<(>>) y$ shifts the bits in $x$ left (right) by $y$. $y$ must be non-negative. 
    - For left shift vacated bits are filled with zero.
    - e.g. `x << 2` shifts $x$ left by 2 (equiv to multiplication by 4)
    - For right shift
        - unsigned types have zero-filling
        - may be either 1's (arithmetic shift) or 0's
        (logic shift) depending on the machine.
- unary operator `~` converts 0-bits to 1-bits and 1-bits to 0-bits.
    - e.g. `x = x & ~077` sets the last six bits to zero.
    - note: `~077` is independent of the word length, while the expression `x & 0177700` assumes a 16 bit word.
        - the former is more portable and both can be determined at compile time so have the same time cost. (since ~077 is constant.)

Consider the example function `getbits(x, p, n)`. This returns the right-adjusted $n$-bit field of $x$ beginning at
$p$. $0$ is taken as the rightmost index, with $p, n > 0$ so
`getbits(x, 4, 3)` returns the three bits at $4,3,2$.

```
/* getbits: get n bits from position p */

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n)
}
```
The expression `x >> (p + 1 - n)` moves the block from
p to p + n to the end of the bitfield
- e.g. if p = 2 and n = 2 and x = 1111, then
    x = 1[11]1 -> [0]1[11] where [0] is a padded zero.
    - (x >> p takes the p-th index to index 0)

~0 is then all 1 bits (word-size independent), left shifting
by $n$, then sets right-most $n$ digits to 0.
- ~(~0 << n) thus sets only the right-most $n$ digits to 1.
- then use `&` to mask. 

### Assignment Operators and Expressions

- Expressions like `i = i + 2` can be written using an
assignment operator
    - has the form (*op*)=
    - operator is one of `+, -, *, /, %, <<, >>, &, ^, |`
    - `(exp1) op= (exp2)` unwraps to `(exp1) = (exp1) op (exp2)`
        - Therefore `x *= y + 1` is:
        - equiv to `x = x * (y + 1)`
        - not equiv to `x = x * y + 1`

- Example: `bitcount` counts the number of set ($1$) bits in
the integer argument.

```
/* bitcount: count 1 bits in x */
int bitcount(unsigned int x)
{
    int b;
    for (b = 0; x != 0; x >>== 1)
    {
        if (x & 01) b++;
    }
    return b;
}
```
- x is declared unsigned to ensure right bitshifts have well-defined behaviour ($0$ padding).
- Generally assignment operators are more readable.
    - Also may help compiler optimisation
- The type and value of all assignment operators is the type of the left operand and the value of the left operand after assignment.

### Conditional Statements

- The ternary operator `?:` lets us rewrite expressions of
the form
```
if (condition)
    (expr1);
else
    (expr2);
```
- `expr1 ? expr2 : expr2` works as follows:
    - *expr1* is evaluated first
        - *expr2* evaluated if result is non-zero (true)
        - *expr3* evaluated if result is zero (false)
- We can thus rewrite
```
if (a > b)
    z = a;
else
    z = b;
```
as
`z = (a > b) ? a : b /* z = max(a, b) */`

- Conditional expression is an expression
    - so can be used where any expression is. 
    - if *expr2* and *expr3* are different types the result
    is converted.
    - e.g. if `f` is a `float` and `n` is an `int` then
    `(n > 0) ? f : n` will be a `float`.
- precedence of `?` is just above `=`
    - use brackets for clarity though.

### Precedence and Order of Evaluation

Precedence: Operator [associativity]

1. `(), [], ->, . [left to right]`
2. `! ~ ++ -- + - * & (type) sizeof [right to left]`
3. `* / % [left to right]`
4. `+ - [left to right]`
5. `<< >> [left to right]`
6. `< <= > >= [left to right]`
7. ` == != [left to right]`
8. `& [left to right]`
9. `^ [left to right]`
10. `| [left to right]`
11. `&& [left to right]`
12. `|| [left to right]`
13. `?: [right to left]`
14. `= += -= *= /= %= &= ^= |= <<= >>= [right to left]`
15. `,`

*Note: the high precedence $-, +, *$, etc are the unary versions*

- Key observation: bit operations have lower precedence than comparisons (`==` and `!=`) so need parentheses for bit-testing.
- C does not specify the order of operand evaluations (except for `&&, ||, ?:, ','`)
    - e.g. `x = f() + g()` may evaluate either `f` or `g`.
        - result becomes machine dependent if `f` or `g` modifies variables the other relies on.
- Order of function arguments also not specified
    - e.g. `printf("%d %d\n", ++n, power(2, n));` is compiler
    dependent.
- Function calls, nested assignments, incr and decr may cause side effects (change variables). May be hard to parse, 
    - e.g. `a[i] = i++` 
    - is the subscript the old or new value? -> compiler dependent.
    - side effect unspecified by standard
        - must take place for function args before function call proceeds

- **MORAL: DON'T RELY ON ORDER OF EVALUATION**
    

    













