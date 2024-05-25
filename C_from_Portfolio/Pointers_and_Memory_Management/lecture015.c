// Dynamically allocated memory (malloc, calloc, realloc, free)

#include <stdio.h>

// stack memory
// variable   address   value
// a          12        5
// b          13        6
// c          14        8
// d          15        10
// e[0]       16        0
// e[1]       17        1
// ...
// e[9]       25        5
// f          26        9


int main(void) {

    // generaly wehn i declared varible the existing in the stack memory will occure
    int a = 5;
    int b = 6;
    func();
    // 

    return 0;
}

void func() {

    int c = 8;
    int d = 10;
    int e[10];
    int f = 9;

    // this will not work:
    // int e[11];
    // to make it possibel this is where the dynamical memory allocation come in 

}
// 3:55:16 / 5:48:37