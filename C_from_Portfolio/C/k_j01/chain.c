#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_book {
    char title[64];
    int pages;
    struct s_book *next;
};
typedef struct s_book Book;

Book *first;
int numBooks;

void addbook(char *title, int pages) {

    Book *p, *new;

    if (!first) {
        p = malloc(sizeof(Book));
        memset(p, 0, sizeof(Book));
        numBooks++;
        strncpy(p->title, title, 63);
        p->pages = pages;

        first = p;

        return;
    }
    for (p = first; p->next; p = p->next);

    new = malloc(sizeof(Book));
    memset(new, 0, sizeof(Book));
    numBooks++;
    strncpy(new->title, title, 63);
    new->pages = pages;

    p->next = new;
}

int main() {

    first = 0;
    numBooks = 0;

    addbook("the bible", 3500);
    addbook("the tora", 1000);
    addbook("the koran", 500);

    printf("%d\n", numBooks);

    printf("First book: %s\n", first->title);
    printf("Second book: %s\n", first->next->title);
    printf("Third book: %s\n", first->next->next->title);

    return 0;
}