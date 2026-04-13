#include <stdio.h>

int main() 
{
    struct student {
        char grade;
        int age;
    };

    struct student s1;
    struct student *ptr;

    ptr = &s1;

    // direct access
    s1.age = 20;

    // acess through pointer
    (*ptr).grade = 'A';
    ptr->age = 21; // same as (*ptr).age = 21;

    printf("Address: %p\n", ptr);
    printf("Age: %d\n", (*ptr).age);
    printf("Grade: %c\n", ptr->grade);

    return 0;
}