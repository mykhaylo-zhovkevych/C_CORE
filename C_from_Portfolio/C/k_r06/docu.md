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