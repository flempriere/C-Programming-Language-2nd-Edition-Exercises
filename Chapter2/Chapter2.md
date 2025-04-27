# Chapter 2: Types, Operators and Expressions

## Examples

### [String Length](./Examples/StrLen/strlen.c)

Computes the length of a string.

### [Leap Year](./Examples/LeapYear/leap_year.c)

Lists the leap years from 1900 to 2100 (inclusive).

### [String to Integer](./Examples/Atoi/atoi.c)

Converts string representations of integers to integers.

### [Uppercase to Lowercase](./Examples/Lower/lower.c)

Converts uppercase characters to lowercase characters.

### [Pseudorandom Number Generator](./Examples/PRNG/rand.c)

Reimplementation of the standard library pseudorandom number generator.

### [Squeeze](./Examples/Squeeze/squeeze.c)

Removes all occurences of a character `c`, from the string `s`.

### [String Concatenation](./Examples/StrCat/strcat.c)

Concatenates two strings.

### [GetBits](./Examples/GetBits/getbits.c)

Extract a bit pattern from an integer.

## Exercises

### [Ex 2-1](./Exercises/Ex2_1/ex2-1.c)

*Write a program to determine the ranges of `char`, `short`, `int` and `long` variables, both `signed` and `unsigned`, by printing appropriate values from standard headers and by direct computation. **Harder if you compute them:** Determine the ranges of the various floating point types.*

**Note**: This is deceptively hard to do in a portable way that doesn't lead to undefined behaviour. The obvious method of integer wrap around is undefined for signed integers.

For the unsigned types, this is straightforward, since we can use wrap around: $`-1`$ corresponds to the maximum, and the minimum is trivially zero. For signed types, the max is half that of the unsigned max (since we have to deal with the sign bit.), but the minimum can either be $`-\text{MAX}`$ (for one's complement, and sign and magnitude) or $`-\left(\text{MAX} +1\right)`$ for two's complement.

However the C23 standard **mandates** that the signed integer representation is *two's complement* which is what we'll use to do this programatically.

For the floating point, we notice that at least on our machine, the calculated minimum is smaller than that reported in `float.h`. This is due to the existence of [subnormal numbers](https://en.wikipedia.org/wiki/Subnormal_number), which should generally be avoided.

### [Ex 2-2](./Exercises/Ex2_2/ex2-2.c)

*Write a loop equivalent to original `get_line` for loop without using `&&` and `||`.*

We can see that the resulting implementation is significantly uglier.

### [Ex 2-3](./Exercises/Ex2_3/ex2-3.c)

*Write the function `htoi(s)` which converts a string of hexadecimal digits (including an optional `0x` or `0x`) into its
equivalent integer value. The allowable digits are $`0`$ though $`9`$, $`a`$ through $`f`$, and $`A`$ through $`F`$.*

Our implementation, is relatively simple, we first check for a prefix, and skip it if its exists. Then while we continue to read
hexdigits we convert them to the appropriate number. We handle uppercase latters by converting them to lower case.

### [Ex 2-4](./Exercises/Ex2_4/ex2-4.c)

*Write an alternate version of `squeeze(s1, s2)` that deletes each character in `s1` that matches any character in the string
`s2`.*

Our implementation loops over the characters in `s2` and runs the previous single character version of `squeeze` on `s1`. An alternative would be to loop over `s1`, check `s2` if the current character is in `s2` and discard it if it is.

Our implementation has the advantage that as `s1` shrinks each time we squeeze, successive searches become faster.

If `s2` has duplicate characters, we could use an array to track the characters we've seen and ignore them. However the overhead of setting up this array for all possible characters (128 in ASCII) means this would only be worthwhile if `s2` is long with a large number of duplicates.

### [Ex 2-5](./Exercises/Ex2_5/ex2-5.c)

*Write the function `any(char s1[], char s2[])` which returns the
first location in the string `s1` where any character from the string `s2` occurs, or `-1` if `s1` contains no characters from `s2`. (The standard library function `strpbrk` does the same job
but returns a pointer.)*

This one is simple again. We loop through `s1` and at each character scan through `s2` to see if there is a match. If there is we return the current index in `s1`. Else if we reach the end of `s1` without a match we return `s2`.

**Note**: This implementation does require us to scan `s2` entirely for every character in `s1` until we get a match. This means that in this case we might consider an array approach as
follows

1. Initialise an array indexed by the character set
2. Scan through `s2` and mark the characters that appear in the array.
3. Scan through `s1` and check the array.

This means that we only have to scan `s1` once, and `s2` once, respectively. Which notionally seems faster. However, we have to initialise the array (for ASCII 128 characters). So for small `s2` strings or `s1` strings this overhead would be more costly than the naive approach we've implemented.

### [Ex 2-6](./Exercises/Ex2_6/ex2-6.c)

*Write a function `setbits(x, p, n, y)` that returns `x` with the `n` bits that begin at position `p` set to the rightmost bits of `y`, leaving the other bits unchanged.*

### [Ex 2-7](./Exercises/Ex2_7/ex2-7.c)

*Write a function `invert(x,p, n)` that returns`x` with the `n` bits that begin at position `p`inverted (i.e. $`1`$ bits set to $`0`$ and $`0`$ bits set to $`1`$.), leaving the others unchanged.*

### [Ex 2-8](./Exercises/Ex2_8/ex2-8.c)

*Write a function `rightrot(x, n)` that returns the value of the integer `x` rotated to the right by `n` bit positions.*

Implementing `rightrot` requires us to calculate the word length of an unsigned. Ideally we would do this once at compile time. This can be done in **C23** using the *_WIDTH macros, but for us
we unfortunately have to calculate it every time the function runs.

A potential extension to this function would be to allow negative values for `n` and to interpret that as a `leftrot` by the absolute value of `n`.

### [Ex 2-9](./Exercises/Ex2_9/ex2-9.c)

*In a two's complement number system `x &= (x - 1)` deletes the righmost $`1`$-bit in `x`. Explain Why. Use this observation to write a faster version of bitcount.*

In a Two's Complement representation, signed integers are represented by the following scheme

1. The highest bit represents the sign.
2. Positive Numbers are represented as $`0[\text{Number in base }2]`$.
3. Negative Numbers are represented by taking the complement of the representatation of their absolute value, and adding 1, ignoring overflow.

Then $`x - 1`$ is equivalent to $` x + (-1)`$ which in the binary representation can be seen as,

```text
    ... xxxx xxxx
  + ... 1111 1111
```

i.e. If we look at every "column" we are adding a $`1`$. Ignoring carry digits for now, this means a $`1`$ becomes a $`0`$ and a $`0`$ becomes a $`1`$. Now consider a carry.

- Every $`1`$ will contribute a carry.
- This carry will propagate up setting every subsequent $`0`$ that was set to $`1`$ back to $`0`$.
- The carry stops propagating when we reach a $`1`$ that was set to $`0`$. But this column has it's own carry digit that continues.
- The only $`1`$ column that does not have a lower carry digit to set it back to $`1`$ is the lowest.
- All columns after this are by the analysis above set back to the same value in `x` before adding $`-1`$.
- Columns with the value of $`0`$ below this lowest $`1`$ bit are set to $`1`$.

Hence the binary representation of `x` and `x - 1` differ only in the value of the bit corresponding to the lowest $`1`$-bit in `x` and the lower $`0`$-bits. So `x &= (x - 1)` clears the lowest $`1`$-bit in `x` leaving the rest untouched.

### [Ex 2-10](./Exercises/Ex2_10/ex2-10.c)

*Rewrite the function `lower`, which converts upper case letters to lower case, with a conditional expression instead of `if-else`.*

## 2.0 Introduction

- *Variables and Constants*: basic data objects, names, types and optionally initial values listed by *declarations*
- *Operators* specify actions taken on data objects
- *Expressions* combine variables and constants to create new values

## 2.1 Variable Names

- Names are made of letters and digits
  - First character must be a letter
  - _ May be used as a letter
    - **Warning** Don't start variables with _, this is reserved for the standard library.
  - Upper and lower case letters are distinct, e.g. `X` != `x`
  - **Note:** convention is to use lower case for *variables* and upper case for *symbolic constants*
- At least first 31 characters of an internal name are significant.
  - May be less for function names and external variables
    - (Since these may be used by assemblers and loaders - language can't control them.)
    - For external names, uniqueness only guaranteed for 6 characters and a single case
- Keywords (e.g. `if, else, int, float`) are reserved.
  - (Also all lower case.)
- Use variable names that are related and unlikely to get mixed up
  - Short names for local variables
  - Longer names for external variables

## 2.2 Data Types and Sizes

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
  - Compiler choses the size but
    - `shorts` and `ints` are at least 16 bits
    - `longs` are at least 32 bits
    - `short` to be no longer than an `int`
    - `int` to be no longer than a `long`.
- e.g. `signed` and `unsigned` which may apply to `char` and any integer type.
  - Unsigned types are non-negative and subject to modulo arithmetic of $2^n$ where $n$ is the number of bits.
  - Signed ints typically use two's complement therefore an 8 bit `char` would have a range from $-128$ to $127$.
  - Plain `char` may be `signed` or `unsigned`, but all printable characters are positive.
- `long double` specifies extended floating point precision
  - implementation is machine dependent, `float`, `double`, `long double` may be one, two or three distinct types.

- The standard headers `<limits.h>` and `<float.h>` contain symbolic constants for these sizes and other
machine and compiler.

### Relevant Exercises

[Ex2.1](#ex-2-1).

## 2.3 Constants

- Integer constant like `1234` is an `int`
- `long` constant written with terminal `l` or `L`
  - e.g. `123456789L`
  - Constants too big for an `int` will also be a `long`
- `unsigned` constants are written with a terminal `u` or a `U` an can be combined with `long` as `ul` or `uL` etc.
- Floating point constants contain a decimal point
(e.g. `1.2`) and/or an exponent (e.g. `1e-2`).
  - Assumed to be `double` unless suffixed with `f` or `F`.
  - May also use `l` or `L` to denote a `long double`.
- Numbers may be specified in *octal* or *hexadecimal* (or from C23 onwards *binary*).
  - Leading `0` denotes octal leading `0x` or `0X` denotes hexadecimal
  - **Note**: In C2y this implicit behaviour will be **obsolete**, instead explicit `0o` prefixes should be used.
    - e.g. `31` (decimal) = `037` (octal) / `0o37` = `0x1F` (hexadecimal)
  - **Note**: C23 adds the binary prefix `0b`
    - e.g. `3` (decimal) = `0b11` (binary)
  - May also be combined with other suffixes
        -e.g. `0xFUL` is an `unsigned long` with a value of 15 (decimal)
- A *character constant* is an integer constant written as a one character with single quotes e.g. `'x'`. The value is the the numeric value assigned to the character in the machine character set.
  - e.g. `'0' == 48 != 0`.
  - This allows characters to be written in a machine independent way.
  - Characters may be be represented in character and string constants by escape sequences (e.g. newline `\n`.)
  - Character constants participate in numerical operations like integers.
- We can specify arbitrary *byte-sized bit patterns*
via `'\ooo'` where `o` is an octal digit or `'\xhh'` where `h` is a hexadecimal digit.
  - e.g.
    - `#define VTAB '\013'` - ASCII vertical tab
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
  - Also called the null.

- A *constant expression* is an expression that contains only constants.
  - Can be evaluated at compile time (and included whereever a constant would be)
  - e.g. `#define MAXLINE 1000`
  - `char line[MAXLINE + 1]`
    or
  - `#define LEAP 1`
  - `int days[31 + 28 + LEAP + etc]`.

- A *string literal* or *string constant* is a sequence of 0+ characters surrounded by *double quotes.*
  - e.g. `"string"`  or `""`
  - Note quotes not part of the string
  - String constants may concatenate at compile time e.g. `"string" "name"` -> `"string name"`.
  - Can split long strings across lines
  - String const is a null-terminated array, therefore space needs is $n + 1$ where $n$ is the number of characters in the string.
    - No restriction on string size.
    - Length must be scanned.

### Example [strlen implementation](#string-length)

- `strlen(s)` is a library function to do this for a string `s`.
- An Example implementation is, (see the code attached.)

```C
int strlen(char s[]) { 
  int i; i = 0; 
  while (s[i] != '\0') { 
    ++i; 
  } return i; 
}
```

- `strlen` and other functions for strings are defined in `string.h`.
- **Warning:** `'x'` is not the same as `"x"`.
  - Former is a character constant
  - Later is a string literal (with implicit null)

- The last type of constant is the *enumeration constant*
  - A list of integer constants, as in
  - `enum boolean {NO, YES};`
  - First has a value of $0$, the second $1$ and so on etc.
    - can provide explicit values, then will be followed on sequentially
    - e.g.

```C
enum escapes {BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r'};`
```

and

 ```C
 enum months {JAN = 1, FEB, MARCH, etc...}
 ```

- Names must be unique in an enumeration but not across all enumerations
- Enums associate constants with names like `define`, but can be checked, and potentially debugged symbolically

## 2.4 Declarations

- Must declare variables before use, often with type
  - Some declarations can be done implicitly
  - Declaration structure is a type, followed by a list of variable names of that type
    - e.g. `int lower, upper, step;`
    - e.g. `char c, line[MAXLINE];`
- Declarations may or may not be assigned with initialisations

```C
char esc = '\\'
int i = 0`
int limit = MAXLINE + 1
double eps = 1.0e-5
```

- **Note**: Prefer this style, its more explicit, and variables should be initialised when they are declared.

- For non-automatic variable, initialisation is done once, (prior to execution).
  - Initialiser must be a constant expression
- Explicitly initialised automatic variable is initialised each time the function or block containing is entered.
  - initialiser may be any expression
- External or static variables are initialised to zero by default
- Uninitialised automatic variables have undefined values.
- `const` may be applied to any variable
  - specifies it will not be changed
  - e.g. `const double e = 2.7182818`
  - e.g. `const char msg[] = "warning: "`
  - May also be used with functions containing array arguments to indicate the array is not changed
    - e.g. `int strlen(const char[]);`
  - Result of attempting to change a `const` variable is implementation defined

## 2.5 Arithmetic Operators

- Binary arithmetic operators are
  - `+, -, *, /` and modulus `%`.
- Integer division truncates fractions
- modulus `%` returns the remainder of `x / y`

### Example [Calculating Leap Years](#leap-year)

An example leap year calculation would then be:

```C
if ((year % 4 == 0 && year % 100 != 0) ||
    year % 400 == 0)
    printf("%d is a leap year\n", year);
else
    printf("%d is not a leap year\n", year);`
```

- `%` operator cannot be applied to floating point types.
- Truncation direction of `/` and sign of `%` for negative numbers is machine dependent.
  - Same for overflow and underflow
- Precedence is (*unary* +, - ) > (*, /, %) > (*binary* +, -).
- Arithmetic operators associate left to right

## 2.6 Relational and Logic Operators

- Relational operators are `>`, `>=`, `<`, `<=`
  - All identical precedence
  - Lower precedence than arithmetic
    - e.g. `i < lim - 1` => `i < (lim - 1)`
- Equality operators ==, != have lower precedence
- Logic operators && and ||.
  - `(expr 1) *logic* (expr 2)` etc. is evaluated left to right
  - Stops once truthfulness established
- e.g. recall

```C
for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
```

The test `i < lim - 1` *must* be made first to ensure there is space for the character, and must stop if this test fails.

Then we need to assign the new char to `c` before we test it's value so `(c = getchar())` *must* occur before comparison

`&&` has higher precedence than `||`
    - Both lower than relational + equality. So

```C
(i < lim - 1) && (c = getchar()) != '\n' && c != EOF
```

does not need brackets.

But `!=` has higher precedence than assignment,

- `c = getchar() != EOF`, compares `getchar()` to `EOF` and then assigns this to `c`.
- A true expression evalutes as `1` while false evaluates as `0`.

Unary negation operator `!` converts non-zero operand into 0 and a zero operand to 1.

- e.g. `if (!valid)` <=> `if (valid == 0)`

### Relevant Exercises

See [Ex2.2](#ex-2-2).

## 2.7 Type Conversions

- Operators acting on multiple types will convert them to a common type based on a small ruleset.
  - Automatic conversions typically only *narrower* -> *wider*
    - e.g. `char` -> `int` -> `long`
  - Or integer to floating point in `f + i`.
- Expressions like using a float as a subscript don't make sense and are forbidden.
- Assignments which lose information, e.g. wider type to narrow (float -> int, int -> char) may cause a warning but are not forbidden.

### Example [String to Integer Conversion](#string-to-integer)

- Chars are small ints.
- Small int, therefore can be used numerically.
- Enables simple character conversions.
- e.g. Naive `atoi()`

```C
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

### Example [Uppercase to Lowercase](#uppercase-to-lowercase)

- We also have the `lower()` function to convert a `char c` to lowercase

```C
/*lower: convert c to lower case: ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c
}
```

- Only works for the ASCII (since the corresponding lower and upper case letters are a fixed numerical distance apart, and they are arranged contiguously).
  - Not strictly true for other sets. e.g. EBCDIC. -> characters are non-contiguous, so other non-alphabetic symbols are converted.

- The standard header `<ctype.h>` provides an interface of functions for tests and conversions independent of character set.
  - e.g. `tolower()` is a character set agnostic version of `lower()` described above.
  - `c >= '0' && c <= '9'` can be replaced by `isdigit()`.

**Warning**: Need to be careful when converting `char` to `int`. Since `chars` can be *signed* or *unsigned* question if a `char` can become a negative integer is open ended.

- Machine dependent
  - Some with a leftmost bit set to $1$ is converted to a negative integer (sign extension)
  - May instead be padded with `0` to an integer
    length.
- C definition ensures any valid char in the character set is converted to a non-negative integer.
  - Arbitrary bit patterns may be positive or negative depending on the machine
    - Specify `unsigned` or `signed` for portability

**Note**: The best habit is to avoid using `char` entirely for non-character values.

Relational expressions like `i > j` (or those connected by `||` and `&&` ) evaluate to $1$ if true else $0$.

- `d = c >= '0' && c <= '9'` assigns $d$ $1$ if $c$ is a digit else $0$.
- Note any non-zero value is treated as true, and this is often used by functions like `isdigit()` and tests for `if, while, for etc...`

### Implicit conversions

Typically *lower* type is promoted to the *higher* type. For unsigned types the informal rules below apply

- If either operand `long double`, convert to `long double`.
- else if operand `double`, convert to `double`
- else if operand `float`, convert to `float`
- else convert `char` or `short` to `int`
- then if either operand `long` convert to `long`.

**Note**: `float` is not implicitly converted to a `double`.

- Math expressions like those in `<math.h>` use double precision
  - Modern header `<tgmath.h>` supports `float`, `long double` etc through one interface.
- `float` typically used to save storage (or time) where either is expensive.

- Conversions are more complicated for *unsigned* types
  - **Warning**: Comparisons are machine dependent (since they dependent on type sizes)
- e.g. if `int` is 16 bit with a 32 bit `long`.
  - `-1L < 1U` as `1U` is promoted to from an `unsigned int` to a `signed long`.
  - But, `-1L > 1UL` because `-1L` is promoted to an `unsigned long` and appears to be a large positive number

- Conversions take place across assignments.
  - Right side value is converted to type on the left.
    - (Which is the type of the result.)
- `char` converts to int according to machine dependent rules
- Longer integers convert to shorter ones or chars by dropping the higher order bits, thus

```C
    int i;
    char c;

    i = c;
    c = i;
```

does not change `c`, the reverse might lose information.

If `x` is `float` and `i` is `int` then
`x = i` and `i = x` both cause conversions.

- `float` to `int` truncates the fractional part
- `double` to `float` either rounds or truncates depending on the implementation.
- Type conversion also occurs during function calls, without a prototype, `char` and `short` -> `int`, `float` -> `double`.

- Explicit conversion can be forced with the type conversion operator called a `cast`:
  - `(type name) expression`
  - Conversion follows rules above
  - Cast acts like assignment to variable of given type
  - e.g. `math.h` function `sqrt()` expects *double* argument, so can use cast for integer arguments
    - e.g. `sqrt((double) n)`.
  - Cast expression is unchanged
  - Same precedence as other unary operators
- Function protoype will automatically coerce arguments.
    e.g. `sqrt` has prototype
        - `double sqrt(double n)`
  - the call
    - `root2 = sqrt(2)`
    coerces the integer 2 into the double 2.0

### Example [Pseudo-Random Number Generator](#pseudorandom-number-generator)

The standard library contains a portable implementation of a pseudo-random number generator, and a seed initialisation function; the former casts,

```C
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

### Relevant Exercises

See [Ex2.3](#ex-2-3).

## 2.8 Increment and Decrement Operators

### Example [Delete a Character from a String](#squeeze)

- Two in(de)crment operators, `++` increases by one, `--` decreases by 1.
  - May be used pre or post fix.
  - `++n` increments *before* the value is used
  - `n++` increments *after* the value is used
    - e.g. if $n = 5$, the `x = ++n` sets $x$ to 6, while `x = n++` sets $x$ to 5.
  - **Note**: expressions like `(i+j)++` is invalid, only works on variables
- While often equivalent, then may not be, consider `squeeze()` below

```C
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

- Each time a non-$c$ occurs, it is copied into the $j$ position and then $j$ is incremented for the next character.
  - `++j` would increment, then copy.

### Example [Concatenating a String](#string-concatenation)

### Relevant Exercises

See [Ex2.4](#ex-2-4) and [Ex2.5](#ex-2-5).

## 2.9 Bitwise Operators

C provides six bitwise operators, typically they may only
be applied to integral operands.

- `&` bitwise AND
- `|` bitwise (inclusive) OR
- `^` bitwise (exclusive) OR
- `<<` leftshift
- `>>` rightshift
- `~` one's complement (unary) (bitwise NOT)

- Bitwise AND is good for masking off bits
  - e.g.  `n & 0177` zeros all but the low-order $7$ bits on $n$
  - (Why? 0177 is an octal representation i.e. `[001][111][111]` then viewed as binary block)
- Bitwise OR is good for setting bits
  - e.g. `x = x | SET_ON`
  - Sets the bits in $x$ to $1$ if they are already set in $x$ or are set in `SET_ON`.

- Bitwise XOR sets a one in each bit position where its operands have different bits and zero where they are the same.

**Note**: the logic operators `&&` and `||` are distinct from the bit operators `&` and `|`.

- e.g. if `x = 1 [01]` and `y = 2 [10]`, then `x & y` is zero, but `x && y` is one.

- Bitshift operators `x <<(>>) y` shifts the bits in $x$ left (right) by $y$. $y$ must be non-negative.
  - For left shift vacated bits are filled with zero.
    - e.g. `x << 2` shifts $x$ left by 2
    - (Equiv to multiplication by 4)
  - For right shift
    - *Unsigned* types have zero-filling
    - *Signed* types may be either 1's (arithmetic shift) or 0's
        (logic shift) depending on the machine.
- Unary operator `~` converts 0-bits to 1-bits and 1-bits to 0-bits.
  - e.g. `x = x & ~077` sets the last six bits to zero.
  - note: `~077` is independent of the word length, while the expression `x & 0177700` assumes a 16 bit word.
    - The former is more portable and both can be determined at compile time so have the same time cost. (since ~077 is constant.)

### Example: [Selecting Bits](#getbits)

Consider the example function `getbits(x, p, n)`. This returns the right-adjusted $n$-bit field of $x$ beginning at
$p$. $0$ is taken as the rightmost index, with $p, n > 0$ so
`getbits(x, 4, 3)` returns the three bits at $4,3,2$.

```C
/* getbits: get n bits from position p */

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n)
}
```

The expression `x >> (p + 1 - n)` moves the block from
p to p + n to the end of the bitfield

- e.g. if p = 2 and n = 2 and x = 1111, then
    `x = 1[11]1` -> `[0]1[11]` where `[0]` is a padded zero.
  - (x >> p takes the p-th index to index 0)

~0 is then all 1 bits (word-size independent), left shifting
by $n$, then sets right-most $n$ digits to 0.

- ~(~0 << n) thus sets only the right-most $n$ digits to 1.
- then use `&` to mask.

### Relevant Exercises

See [Ex 2.6](#ex-2-6), [Ex 2.7](#ex-2-7) and [Ex 2.8](#ex-2-8)

## 2.10 Assignment Operators and Expressions

- Expressions like `i = i + 2` can be written using an
assignment operator
  - Has the form (*op*)=
  - Operator is one of `+, -, *, /, %, <<, >>, &, ^, |`
  - `(exp1) op= (exp2)` unwraps to `(exp1) = (exp1) op (exp2)`
    - Therefore `x *= y + 1` is:
    - Equivalent to `x = x * (y + 1)`
    - Not equivalent to `x = x * y + 1`

### Example [bitcount](./Examples/BitCount/bitcount.c)

```C
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

### Relevant Exercises

See [Ex 2.9](#ex-2-9)

## 2.11 Conditional Statements

- The ternary operator `?:` lets us rewrite expressions of
the form

```C
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

```C
if (a > b)
    z = a;
else
    z = b;
```

as

```C
z = (a > b) ? a : b /* z = max(a, b) */
```

- Conditional expression is an expression
  - So can be used where any expression is.
  - If *expr2* and *expr3* are different types the result
    is converted.
  - e.g. If `f` is a `float` and `n` is an `int` then
    `(n > 0) ? f : n` will be a `float`. (Irrespective of which branch is taken.)
- Precedence of `?` is just above `=`
  - Use brackets for clarity though.

### Example uses

Print the contents of an array, 10 elements per line.

```C
for (int i = 0; i < n; i++) {
  printf("%6d%c", a[i], (i % 10 == 9) || i == (n - 1)) ? '\n' : ' ';
}
```

Conditionally printing the s for singular vs plural

```C
printf("You have %d items%s.\n", n, (n == 1) ? "" : "s");
```

### Relevant Exercises

See [Ex2.10](#ex-2-10).

## 2.12 Precedence and Order of Evaluation

### Table of Operator Precedence

| Operators                                | Associativity |
|------------------------------------------|---------------|
| () [] -> .                               | left to right |
| ! ~ ++ -- + - * & (type) sizeof          | right to left |
| * / %                                    | left to right |
| + -                                      | left to right |
| << >>                                    | left to right |
| < <= > >=                                | left to right |
| == !=                                    | left to right |
| &                                        | left to right |
| ^                                        | left to right |
| \|                                       | left to right |
| &&                                       | left to right |
| \|\|                                     | left to right |
| ?:                                       | right to left |
| = += -= *= /= %= &= ^= \|= <<= >>=       | right to left |
| ,                                        | left to right |

*Note: the high precedence $-, +, *$, etc are the unary versions*

- Key observation: bit operations have lower precedence than comparisons (`==` and `!=`) so need parentheses for bit-testing.
- C does not specify the order of operand evaluations (except for `&&, ||, ?:, ','`)
  - e.g. `x = f() + g()` may evaluate either `f` or `g`.
    - Result becomes machine dependent if `f` or `g` modifies variables the other relies on.
- Order of function arguments also not specified
  - e.g. `printf("%d %d\n", ++n, power(2, n));` is compiler
    dependent.
- Function calls, nested assignments, incr and decr may cause side effects (change variables). May be hard to parse,
  - e.g. `a[i] = i++`
  - Is the subscript the old or new value? -> compiler dependent.
  - Side effect unspecified by standard
    - Must take place for function args before function call proceeds

- **MORAL: DON'T RELY ON ORDER OF EVALUATION**
