#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void example02();

// it creates type synonym for type int calles inches and it improves the rediability of the code 
typedef int inches;

// the typedef is oftend used in conjuction with the struct 
struct Point {

    // this x and y are members of the struct 
    int x;
    int y;

};

int main(void) {

    struct Point p1;
    p1.x = 5;
    p1.y = 1;
    printf ("(%d, %d)\n",p1.x, p1.y);   

    inches person1 = 192;
    inches person2 = 129;

    printf("person1: %d\n", person1);
    printf("person2: %d\n", person2);


    struct Point p2;
    p2.x = 10;
    p2.y = 12;
    printf ("(%d, %d)\n",p2.x, p2.y);

    struct Point p3 = {1,2};
    printf ("(%d, %d)\n",p3.x, p3.y);

    struct Point p4 = {
        // it is fine to initialize the varibale out of the original order 
        .y = 7,
        .x = 6
    };

    printf ("(%d, %d)\n",p4.x, p4.y);


    typedef struct 
    {
        int a;
        int s;
    } Dot;
    
    Dot d1 = {.a = 6, .s = 19};
    printf("(%d, %d)\n", d1.a, d1.s);

    example02();

    return 0;
    
}


void example02() {

    typedef struct {
        char first_name[50];
        char last_name[50];
        int age;
    } Student;

    Student s1;
    s1.age = 20;
    strcpy(s1.first_name, "Patric");
    strcpy(s1.last_name, "Booton");

    printf("%s %s\n", s1.first_name, s1.last_name);

    printf("Age: %d\n", s1.age);

}