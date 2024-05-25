// dereferencing a pointer means accessing the value stored at the memory address that the pointer is pointing to. When you dereference a pointer, you use the * operator to obtain the value at the address held by the pointer.
// Example: 
// int x = 10; // An integer variable
// int *p = &x; // A pointer that holds the address of x

// Dereferencing the pointer p
// int value = *p; // value is now 10, which is the value stored at the address p points to

// Pointer notation vs array notation
#include <stdio.h>

void add_one(int array[], int length);
void add_b(int array[], int length);

int main(void) {
    // Demonstration of add_one function with array notation
    int a[] = {1, 2, 3};
    // Passing the array to the function. The array decays to a pointer
    // What is really passed here is the memory address where the values 1, 2, 3 are stored
    // and the function add_one will accept that memory address (int array[])
    add_one(a, 3);
    for (int i = 0; i < 3; i++)
        printf("a[%d] = %d\n", i, a[i]);

//             address  value
// index  0    55       1 
//        1    56       2
//        2    57       3
//
//        p    200      55
// like the pointer p points to the first memorry address 55 and than i can access the memory by the p 
   int numbers[] = {1, 2, 3};
   int *p;
   p = numbers; 
   // array notation
   // array notation can be used with array and pointers
   printf("p: %p\n", p);
   printf("a: %p\n", numbers); 
   // the pointer is storred in the same memory address as the array
   printf("%d\n", p[0]);

   // pointer notation
   printf("*(p + 1) = %d\n", *(p + 2));
   printf("*(numbers + 1) = %d\n", *(numbers + 2)); 
   // can be looking like the pointer and the array can be used interchangeably but actually not relly   
   //numbers = p; 
   //in C, arrays are not modifiable lvalues, which means you cannot assign a new address to an array variable once it has been declared. This will result in a compilation error. 
   
   // PRACTICAL EXAMPLE OF THE POINTER ARITHMATIC 
   int b[] = {1,2,3,4,5,6,7,8,9,10};
   add_b(b + 5, 5);
   for (int i = 0; i < 10; i++)
        printf("b[%d] = %d\n", i, b[i]);
        /*  OUTPUT:
        b[0] = 1
        b[1] = 2
        b[2] = 3
        b[3] = 4
        b[4] = 5
        b[5] = 7
        b[6] = 8
        b[7] = 9
        b[8] = 10
        b[9] = 11 
        */
        // here the only backhelf has been updated, because the pointer arithmetic was used here
        // Instead of incrementing the entire array, only the offset addresses will be updated
   return 0;
}

// Function using array notation
// somethimes the arrays take be treated as the pointer and the pointer as the arrays but very often 
void add_one(int array[], int length) {
    for (int i = 0; i < length; i++)
        array[i] += 1;
}

void add_b(int array[], int length) {
    for (int i = 0; i < length; i++)
        array[i] += 1;
}


