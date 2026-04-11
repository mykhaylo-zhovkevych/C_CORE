Pointers in C exist because C gives you direct access to memory addresses. A pointer is a variable whose value is the address of an object or function; it can also be a null pointer that points to nothing.
``` c
#include <stdio.h>
int main() {
    int x, y;
    int* px; // hold memory of int

    x = 42;
    px = &x; // stores the address of x into px
    y = *px; // follow the address in px dereference
    printf("%d %p %d\n", x,px,y); // 42, 0x12f5b31ec, 42
}
```
But pointers exist for situations where direct copy is not enough
1. - I want a function to modify the original
``` c
void addTen(int *px) {
    *px = *px + 10;
} 
int x = 42;
addTen(&x);
printf("%d", x); // 52

// Without pointer
void addTen(int x) {
    x = x + 10; // only modifies the local copy
} 
// x 42 stays the same
```
2. - I wnat to avopid copying large date:
``` c
void process(BigStruct s) // copies All the data, slow
void processs(BigStruct *s) // 8 Bytes regardless of struct size
```

``` c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x; // Pointer dereferencing means: **using a pointer to access the value stored at the memory address inside it.**

    printf("x = %d\n", x);     // 10
    printf("*p = %d\n", *p);   // 10

    *p = 20;

    printf("x = %d\n", x);     // 20
    printf("*p = %d\n", *p);   // 20

    return 0;
}
