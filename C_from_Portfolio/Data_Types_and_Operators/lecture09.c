// Arrays in the lecture08

/* In C programming, a string is essentially an array of characters terminated by a null character (\0). 
This null character is very important as it indicates where the string ends. 
Unlike higher-level languages which have dedicated string data types with built-in functions for manipulation, 
C handles strings as character arrays, 
which gives programmers flexibility but also places the responsibility of managing them correctly. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // Call the function from main
    printCharacterInfo();
    printCharacterOnLength();
    thelibrorystring();
    concatenation();
    concatenation02();

    return 0;
}


int printCharacterInfo(void) {

    char mydate[5];

    mydate[0] = 'a';
    mydate[1] = 'b';
    mydate[2] = 'c';
    mydate[3] = 'd';

    mydate[4] = '\0'; // sepetial character for to maker where the string must end // non-printable

    printf("mydate[2] = %c\n", mydate[2]);

    printf("\n%s\n", mydate); // %s is placehodler for outputing a string

    // shortcut
    char s1[] = "this is my string.";

    // prints a each char
    for (int i = 0; i < 19; i++) {
    if (s1[i] == '\0'){
        printf("s1[%d] = \\0 \n", i);
    } else
    printf("s1[%d] = %c\n", i, s1[i]);
    }

    printf("\n%s\n", s1);

    return 0;
}

int printCharacterOnLength() {

    char s2[20];
    printf("Enter: ");
    scanf("%s", s2); //noneterminatpr will putted automatically 

    int i = 0;
    while (s2[i] != '\0' )
    {
        if (s2[i] == '0') 
        printf("found 0\n");
        i++;
        
    }
    

    printf("s2: %s\n", s2);


    return 0;
}

// string.h gives bunh of function that simplify the work with strings  

int thelibrorystring(void) {

    char s3[] ="this is the way.";

    // this function find the length of the string  witout the terminator 
    int length = strlen(s3);
    int num_is = 0;

    for (int i = 0; i < length; i++) 
        if (s3[i] == 'i') num_is++;
    

    printf("length: %d\n", length);
    printf("Number of i is: %d\n", num_is);

    return 0;

}

int concatenation(void) {

    char s4[50] = " this is the first sentence. ";
    char s5[] = " this is the secound setence. ";

    if (strcmp(s4,s5) == 0)
        printf("s4 and s5 are equal\n");
    else 
        printf("not equal");

    strcat(s4, s5);
    printf("s4: %s\n", s4);


    return 0;
}

// #include <ctype.h> this library allow make strings upper or lower cases
int concatenation02(void) {

    char s6[] = "This is A WaY.";
    // flips the cahr to another form
    //storage   |  convertion
    s6[0] = tolower(s6[0]);
    s6[0] = toupper(s6[5]);

    int length = strlen(s6);
    for (int i = 0; i < length; i++) {
        printf("%c ", s6[i]);
        if (isupper(s6[i])) {
            printf("upper\n");
        } else if ( islower(s6[i])) {
            printf("lower\n");
        } else
            printf("\n");
    }

}


