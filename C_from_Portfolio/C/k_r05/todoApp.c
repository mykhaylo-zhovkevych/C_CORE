#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//that means each todo item is stored in a node, and each node contains
typedef struct ToDo todo; // shortcut

struct ToDo{
 char data[100];
 todo *link; // points to another node
 int count;
};

void welcomeUser(void);
void seeToDo(void);
void createToDo(void);
void delToDo(void);
void fixcount(void);
//void updateToDo(void);
void clearScreen(void);
void waitForEnter(void);

//global pointer to the start of the linked list
todo *start=NULL;

int main(void)
{
    int choice;
    welcomeUser();
    while(1){
        clearScreen();
        printf("\n1.See Your ToDo List");
        printf("\n2.Create Your ToDos");
        printf("\n3.Delete Your ToDos");
        printf("\n4.Update Your ToDos");
        printf("\n5.Exit");
        printf("\n\nEnter your choice..");
        scanf(" %d",&choice);

    switch(choice){
      case 1:
          seeToDo();
        break;
      case 2:
          createToDo();
        break;
      case 3:
          delToDo();
        break;
      case 4:
         //updateToDo();
         break;
      case 5:
        exit(0);
        }
    }
}

void welcomeUser(void) {
    printf("\nWelcome to the ToDo App!\n");
    printf("\t--********************--\n");
    waitForEnter();
}

void seeToDo(void) {
   clearScreen();
   todo *temp;
   temp=start;
        if(start==NULL) {
           printf("\nEmpty TODO\n\n");
        }

       while(temp!=NULL) {
        // go to the struct object that this pointer points to, then access one of its fields
          printf("%d)",temp->count);
          puts(temp->data);
          
          //move the pointer to the next node in the list by following the link
          temp=temp->link;
       }
       printf("\n\n\n");
       waitForEnter();
   }

void createToDo(void) {
    char k;
    todo *t,*temp;
    clearScreen();
    while(1) {
        printf("\nWant to add?y/n");
        scanf(" %c",&k);
            if(k=='n')
                break;
            else {
                if(start==NULL) {
                //allocate memory for a new node and assign its address to the pointer t
                //convert generic pointer to todo pointer
                t=(todo *)calloc(1,sizeof(todo));
                start=t;
                printf("\nADD it..\n");
                //Loop keeps discarding chars until it reaches newline
                while (getchar() != '\n') {
                }
                if (fgets(t->data, sizeof t->data, stdin) != NULL) {
                t->data[strcspn(t->data, "\n")] = '\0';
                }
                t->count=1;
                start->link=NULL;
            } else {
                //t points to the current last node
                temp=(todo *)calloc(1,sizeof(todo));
                printf("\nADD it..\n");
                //Loop keeps discarding chars until it reaches newline
                while (getchar() != '\n') {
                }
                if (fgets((*temp).data, sizeof temp->data, stdin) != NULL) {
                temp->data[strcspn(temp->data, "\n")] = '\0';
                }
                temp->link=NULL;
                // Node A stores Node B address
                t->link=temp;
                t=t->link; // move t to the new last node
            }
        fixcount();
        }
    }
}

void delToDo(void) {
  clearScreen();
  int d;
  todo *temp1,*temp2;
  printf("\nEnter the number of the todo you want to remove\n");
  scanf("%d",&d);
  temp1=start; // A holds B
  temp2=start->link; // B
    while(1) {
        if(temp1->count==d) {
            // points to B and not A(Node1)
            start=start->link;
            free(temp1);
            fixcount();
            break;
        }
        if(temp2->count==d) {
            //take B and point to A
            temp1->link=temp2->link;
            free(temp2);
            fixcount();
            break;
        }
        // if not found
        else {
            temp1=temp2;
            temp2=temp2->link;
        }
    }
    waitForEnter();
}

void fixcount(void) {
  todo *temp;
  int i=1;
  temp=start;
  while(temp!=NULL) {
    temp->count=i;
    i++;
    temp=temp->link;
  }
}

// void updateToDo(void) {
//   clearScreen();
//   todo *temp,*t;
//   char k;
//   while(1){
//         printf("\nWant to add?y/n");
        
//         scanf(" %c",&k);
//         if(k=='n')
//             break;
//         else {
//             while (getchar() != '\n') {
//             }
//             printf("\nADD it..\n");
//             temp=(todo *)calloc(1,sizeof(todo));

//             if (fgets(temp->data, sizeof temp->data, stdin) != NULL) {
//                 temp->data[strcspn(temp->data, "\n")] = '\0';
//             }
//             temp->link=NULL;
//             t=start;
//         while(t->link!=NULL) {
//             t=t->link;
//         }
//         t->link=temp;
//         fixcount();
//     }
// }
// printf("\n\n");
// waitForEnter();
// }

// Helper function
void clearScreen(void) {
    printf("\033[2J\033[H");
    fflush(stdout); // force output immediately
}
void waitForEnter(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    printf("Press Enter to continue...");
    getchar(); // wait for Enter key
}