#include <stdio.h>

int main(void) {

    int height = 0;
    int weight = 56;

    printf("height: ");
    scanf("%d", &height);

    if(height <= 155 )
    printf("Not tall enough!\n");
    else 
    printf("Tall enough!\n");

        // logical operators 
        // ( ! (heght > 150) )
    	if (height > 150 || weight > 50)
        printf("Good to ride!\n");
         else
        printf("Not good to ride!\n");

    return 0;
}