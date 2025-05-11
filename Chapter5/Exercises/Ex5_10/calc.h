/**
 * @file calc.h
 * @author Felix Lempriere
 * @brief Updated calculator header file for Ex5.10 supporting additional
 * functionality and allowing getch to be rebinded to read from the command-line.
 * @version 0.1
 * @date 2025-05-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

//getop return codes

/**
 * @brief Signal that a number was found.
 *
 */
 #define NUMBER '0'

/**
 * @brief Indicates a query of the top of the stack
 *
 */
#define TOP '?'

/**
 * @brief Indicates to duplicate the top of the stack
 *
 */
#define DUPLICATE '~'

/**
 * @brief Indicates to swap the top two elements of the stack
 *
 */
#define SWAP '@'

/**
 * @brief Clears the stack
 *
 */
#define CLEAR '#'

/**
 * @brief Indicates a mathematical function has been called
 *
 */
#define MATH_FUNC '1'

/**
 * @brief Indicates variable assignment
 *
 */
#define VARIABLE_ASSIGNMENT '='

/**
 * @brief Symbol for the variable storing the last printed value
 *
 */
#define LAST_PRINTED '$'

/**
 * @brief Gets the next operator or operand
 *
 * @param s buffer to store the next operator or operand.
 * @return int value denoting the operator, or the that the buffer
 * contains an operand.
 */
int getop(char s[]);


//math function handling

/**
 * @brief Matches a string to the appropriate mathematical function to call.
 *
 * @param s string containing the name of the mathematical function to call.
 */
void mathfn(char s[]);

/**
 * @brief Prints an error diagnostic if a math function is called with an
 * invalid value.
 *
 * @param s string representation of the math function
 * @param x value the function was called with
 * @param lower lower bound for valid input
 * @param upper upper bound for valid input
 */
void RangeError(char s[], double x, double lower, double upper);

//stack functions

/**
 * @brief Push a value onto the stack.
 *
 * @param v
 */
void push(double v);

/**
 * @brief Pop a value from the stack
 *
 * @return value on top of the stack. The item is removed
 * from the stack.
 */
double pop(void);

/**
 * @brief Prints the top of the stack without popping it.
 *
 * @return value on top of the stack. The element remains on
 * the stack.
 */
double top(void);

/**
 * @brief Swaps the top two elements of the stack.
 *
 */
void swap(void);

/**
 * @brief Duplicates the element on the top of the stack
 *
 */
void duplicate(void);

/**
 * @brief Clears the stack
 *
 */
void clear(void);

// I/O Functions

/**
 * @brief Sets getch to read from a provided array of strings of length l, rather
 * than the standard input. Can be used to configure getch to handle commandl
 * line arguments.
 * 
 * @param l length of the string array.
 * @param s array of strings.
 */
void set_input(int l, char* s[]);

/**
 * @brief Fetches a character from input.
 *
 * @return int
 */
int getch(void);

/**
 * @brief Push a character back onto the input buffer
 *
 * @param c character to push back
 */
void ungetch(int c);

