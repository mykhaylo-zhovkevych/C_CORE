the order evaluation is not specified for aassociative and commutative operators like * and +; the compiler may rearange a parenthesized computation.
If the order must be guaranteed than a simple varible decalration can help with seperation with statements.
``` c
// wrong order 
int sum = next() + next() + next();

// correct order
int a = next();
int b = next();
int c = next();
int sum = a + b + c;
// Each statement in C is a sequence point
``` 
The same mindset applies everywhere, but in the higher languages it is done automatically
``` c#
int counter = 0;
int Next() => ++counter;

int oneLiner = Next() + Next() + Next(); // Always 1+2+3 = 6, spec guarantees it

// split version readability
int a = Next();  // 1
int b = Next();  // 2
int c = Next();  // 3
int split = a + b + c;
```
