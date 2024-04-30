// 1. Basic Arithmetic Operators
// Addition (+): Adds two operands.

int a = 5, b = 3;
int sum = a + b;  // sum is 8

// Subtraction (-): Subtracts the second operand from the first.



int difference = a - b;  // difference is 2

// Multiplication (*): Multiplies two operands.


int product = a * b;  // product is 15

// Division (/): Divides the first operand by the second. Note: If both operands are integers, the result is an integer (floor division).



int quotient = a / b;  // quotient is 1

// Modulus (%): Returns the remainder of the division of the first operand by the second.



    int remainder = a % b;  // remainder is 2

// 2. Compound Assignment Operators

// C also offers compound assignment operators that combine an arithmetic operation with assignment. These make the code shorter and often clearer:
// Addition assignment (+=):

a += b;  // equivalent to a = a + b

// Subtraction assignment (-=):

a -= b;  // equivalent to a = a - b

// Multiplication assignment (*=):


a *= b;  // equivalent to a = a * b

// Division assignment (/=):


// a /= b;  // equivalent to a = a / b

//bModulus assignment (%=):


    a %= b;  // equivalent to a = a % b

// 3. Increment and Decrement Operators

//These operators increase or decrease a variable's value by one, which is very useful in loops and conditional execution:

//Increment (++):


a++;  // equivalent to a = a + 1

// Decrement (--):


    a--;  // equivalent to a = a - 1

// 4. Advanced Usage
//Operator Precedence and Associativity
//Understanding the precedence and associativity of operators is crucial for determining the order in which parts of an expression are evaluated. For instance, multiplication and division have higher precedence than addition and subtraction.

int result = 3 + 4 * 5;  // result is 23, not 35

//Type Conversions
//When operands of different types are used in arithmetic operations, C automatically converts them to a common type according to a set of rules, often called the "usual arithmetic conversions".


double result = 5 / 2;  // result is 2.0, not 2.5
double correctResult = 5 / 2.0;  // correctResult is 2.5

//Overflow and Underflow
// Understanding integer overflow and underflow can help prevent bugs:


unsigned int u_max = UINT_MAX;
u_max++;  // Wraps around to 0, demonstrating overflow

int i_min = INT_MIN;
i_min--;  // Wraps around to INT_MAX, demonstrating underflow

// 5. Optimizing Arithmetic Operations
//Optimizing arithmetic computations can significantly impact performance, especially in systems with limited resources or applications requiring high-speed processing:
//Using bit shifts for multiplications or divisions by powers of two: This can be faster than using standard multiplication or division, especially in embedded systems.

int x = 5;
int y = x << 1;  // Equivalent to x * 2
int z = x >> 1;  // Equivalent to x / 2

// Exploiting compiler optimizations: Understanding how different compilers optimize arithmetic can lead to more efficient code.