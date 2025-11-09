
#ifndef book_h
#define book_h

typedef struct 
{
    int id ;
    char title[100];
    char author[100];
    int is_borrowed;
}Book;

void addBook(Book books[], int *n);
void editBook(Book books[], int n);
void deleteBook(Book books[],int *n);
void listBook(Book books[],int n);

#endif
