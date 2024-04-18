#include <stdio.h>
/* The Input-Processing-Output (IPO) model is a basic conceptual template that describes how functional systems (including simple programs) operate. It consists of three main parts:
    Input: The data received by the system, which could be from user input, a file, or another system.
    Processing: The operation or series of operations performed on the input to transform it into something useful. This is where the core logic of the program or system resides.
    Output: The result of the processing stage, which is sent out of the system. This could be displayed to the user, stored in a file, or sent over the network. */
int main() {
    // Declare variables for input
    // this idea of just declaring variables not the best because this can have like some garbage values that is obsure
/*     double length, width, area;

    // Input: Get length and width of the rectangle from the user
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);  // 'lf' is the format specifier for double in scanf
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    // Processing: Calculate the area of the rectangle
    area = length * width;

    // Output: Display the area of the rectangle
    printf("The area of the rectangle is: %.2f square units\n", area);

    return 0; */

    /* float x = 5.3;
    double y = -9.8;

    printf("x: ");
    scanf("%f", &x);
    printf("x: %f", x); */
    
    // char requires the '' and not "" how Strings
    int speed = 10; 
    char c = 'd';
    double x = 2.3;
    float y = -2.4;
    // all this is Literal values 

    printf("c: ");
    scanf("%c", &c);
    // d is placeholder for int values
    printf("c: %d\n", c);

    int x = 11, y = 3;


/*  int div = x / y;
    int mod = x % y;

    printf("div: %d\n",  div);
    printf("mod: %d\n",  mod);
 */
    return 0;

}

// 39:26 / 5:48:37 // https://www.youtube.com/watch?v=ssJY5MDLjlo&list=LL&index=3&t=1833s