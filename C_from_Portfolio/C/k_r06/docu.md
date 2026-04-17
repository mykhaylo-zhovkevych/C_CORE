A struct is a user defined type that contains one or more types that can be treated as a unit.
The elements or variables mentioned is a structure are called members. The dot operator allows us to aceess the members of the structure

``` c
#include <stdio.h> 
struct point {
    double x;
    double y;
};
void func(struct point pf)
{
    pf.x = 9.0;
    pf.y = 8.0;
    printf("func %f %f\n", pf.x, pf.y);
}

int main () 
{
    struct point pm;

    pm.x = 3.0;
    pm.y = 4.0;

    printf("main %f %f\n", pm.x, pm.y);
    func(pm); // changes locally, entire struct is duplicated into the stack frame 
    printf("back %f %f\n", pm.x, pm.y);
}
``` 
Secound updates the values permanently because of the pass by pointer, which changes the original struct
``` c
#include <stdio.h>

struct point 
{
    double x; 
    double y;
};

void func(struct point *pp)
{
    pp->x = 9.0;
    pp->y = 8.0;
    printf("func %f %f\n", pp->x, pp->);
}

int main() 
{
    struct point pm;

    pm.x = 3.0;
    pm.y = 4.0;

    printf("main %f %f\n", pm.x, pm.y);
    func(&pm);
    printf("back %f %f\n", pm.x, pm.y);
}
``` 

``` c
#include <stdio.h>
void doubleValues(int *p, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        *(p + i) *= 2;
    } 
}

int main(void) 
{
    int arr[4] = {1,2,3,4};

    // &arr[0]
    doubleValues(arr, 4);

    for (int i = 0; i <4; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

#### Classical Example
``` c 
#include <stdio.h>

void swap(int *n, int *n1)
{
    int tmp;

    tmp = *n;
    *n = *n1;
    *n1 = tmp;
}

int main() 
{
    int a;
    int b;

    a = 42;
    b = 1337;
    printf("a->%d\tb->%d\n", a, b);
    swap(&a, &b);
    printf("a->%d\b->%d\n", a, b);
}

int x = 42;

// int *p = &x;     // pointer to int
// int **pp = &p;   // pointer to pointer to int

// printf("%d\n", x);
// printf("%d\n", *p);   
// printf("%d\n", **pp); 
// Used for Modifying a pointer inside a function
void allocate(int **p) {
    *p = malloc(sizeof(int));
    **p = 100;
}
// Dynamic 2D arrays
int **matrix
// Accessing the array of pointers like 
char *names[] = {"Alice", "Bob"};
char **p = names;
``` 

``` c
#include <stdio.h>

void printData(void *data, char dataType)
{
    if (dataType == 'i')
        print("Integer: %d\n", *((int*)data));
    else if (dataType == 'f')
        printf("Float: &E\n", *((float*)data));
    else if (dataType == 'c')
        printf("Character: %c\n", *((char*)data));
    else 
    printf("Unknown data type.\n");
}
int main() 
{
    int intValue = 42;

    printData(&intValue, 'i');
    printData(&intValue, 'f');
    printData(&intvalue, 'c');
}
```

``` c
#include <stdio.h>
#include <stdlib.h>

// the 42 will be placed at the heap 
// and the 1337 will be at the stack
void bar()
{
    int nb;
    nb = 1337;
}

int *foo()
{
    int *n;
    // allocates memory on the heap
    n = malloc(sizeof(int));
    *n = 42;
    return n; // address of that memory
}

int main ()
{
    int *pn;

    pn = foo();
    printf("%d\n", *pn);
    bar();
    printf("%d\n", *pn);
}
```

_Pointer and Array_
“The name of an array is a synonym for the location of the first element”
it feels like a pointer
``` c
int arr[3] = {10, 20, 30};
printf("%d\n", *arr);
printf("%d\n", *(arr+1));  
```
But it is not a pointer 
I cannot reassign it:
`arr = some_other_array`  

but with pointer i can
``` c
int *p;
p = arr;
p = other_arr; 

// And 
int arr[3];
int *p = arr;

sizeof(arr); // 12 (3 ints)
sizeof(p);   // 8  (pointer size)
```

``` c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // array
    int arr[10];
    arr[0] = 42;
    arr[1] = 123;
    arr[2] = 3211;

    //printf("%p == %p\n", arr, &arr[0]); // two equal addresses

    for (int i = 0; i < 10; i++)
        printf("%d\n", *arr++);
    
    printf("%zu\n", sizeof(arr)); // 40

    // fake array
    // const pointer to int
    int * const ptr = alloca(sizeof(int) * 10);

    *(ptr + 0) = 42;
    *(ptr + 1) = 142;
    *(ptr + 2) = 4102;

    for (int i = 0; i < 10; ++i)
        printf("%d\n", *ptr++ );

    printf("%zu\n,", sizeof(ptr)); // 8
}
// Is array a constant pointer?
//It only behaves similarly in some cases, because it cannot be modified and decays to a pointer in expressions
//An array is not a pointer, but in most expressions it acts like a read-only pointer to its first element
```