#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "book.h"
#include "user.h"

void borrowBook(Book books[], int nBook, user_t users[], int nUser);
void returnBook(Book books[], int nBook, user_t users[], int nUser);

#endif
