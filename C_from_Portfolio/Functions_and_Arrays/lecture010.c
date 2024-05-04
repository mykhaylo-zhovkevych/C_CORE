#include <stdio.h>

// function declaration 
int find_max(int a, int b);

int main(void) {
    
    int max = find_max(10, 15);
    printf("max: %d\n", max);

    return 0;
} 


int find_max(int a, int b){
    if (a > b ) return a;
    else return b;

}

// ------ Example02 ------

double add(double x, double y);

int main(void) {
    printf("%f\n", add(104.3, 12.0));
    return 0;
}

double add(double x, double y) {
    double result = x + y;
    return result;
}

// ------ Example03 ------

float triple(float n);

int main(void) {
    float x =5.0;
    x = triple(x);
    printf("x:%f\n", x);

    return 0;
}

float triple(float n) {
    
    n = n * 3;
    return n;
}

// ------ Example04 ------


double mult(double x, double y);
double power(double x, int n);

int main(void) {
    printf("%f\n", power(2,3));
     printf("%f\n", power(5,7));
      printf("%f\n", power(3,2));

    return 0;

}

double mult(double x, double y) { return x * y; }

double power(double x, int n) {
    double result = x;
    for (int i = 1; i < n; i++) {
        result = mult(result, x);
    }
    return result;
}

// ------ Example05 ------

void print_two(float a, float b);

int main(void) {
    float x= 2.5, y = 4.3;
    print_two(x, y);

    return 0;
}

void print_two(float a, float b) {
    printf("%f\n%f}n", a, b);
}

/* 1. Local Scope (Block Scope)
Variables declared within a function or a block are local to that function or block. 
They cannot be accessed outside of it. 
This type of variable only exists for the duration of that function or block execution. */
/* 
void function() {
    int localVar = 5;  // localVar is local to function
    printf("%d\n", localVar); // Prints 5
}

int main() {
    // printf("%d\n", localVar); // Error: localVar is not accessible here
    function();
    return 0;
} */
// ---------------------------------------------------------------------------------------
/* 
2. Global Scope
Variables declared outside all functions are global variables. 
They can be accessed from any part of the program that comes after the declaration, by any function or block
 */
/* int globalVar = 5;  // globalVar is accessible throughout the program

void function() {
    printf("%d\n", globalVar); // Accessible here
}

int main() {
    printf("%d\n", globalVar); // Also accessible here
    function();
    return 0;
}
 */