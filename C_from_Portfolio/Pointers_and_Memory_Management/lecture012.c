#include <stdio.h>

int main(void) {

/* 
variables     address     value
a (int)       55          5
b (int)       56          10
p (pointer)   57          56

 */

    // these are boxes that store value in the memory, each has it is own address
    int a = 5;
    int b = 10;

    // p stores the pointer to the int, it dont stores thre int but the pointer and the p also has some memory address 
    int *p;
    // & and operator means get the memory address of this b 
    // and the p is storing the memory address of the b so like it is poining to the memory address
    p = &b;
    
    //Pointer differencing refers to subtracting one pointer from another. This operation determines the number of elements between the two pointers when they point to elements of the same array.
                  //this *p is not the same as the int *p this one is fordeclering the pointer 
                  // and this one is for differencing the pointer
                  // and the main point of it is to get the value at the address that p is poining to LIKE: ==>
                  // LIKE wehn i do this(differencing) i am using the p(57) and i am getting the value 10 of b becasue the p is poting to the b address 56
    printf("%d\n", *p);
    a = a + *p;
    printf("a: %d\n", a);
    //OUTPUT 10 a: 15

    printf(" p: %p\n", p);
    printf("&b: %p\n", &b);
    printf("&a: %p\n", &a);
    // reasinging the pointer
    p = &a;
    printf(" p: %p\n", p);

    // with the pointer tha value has been changed
    *p = *p + 1;
    printf("a: %d\n", a);
     //OUTPUT a: 6
    return 0;
}