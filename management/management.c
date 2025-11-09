#include "management.h"
#include <stdio.h>
#include <string.h>



// Mượn sách
void borrowBook(Book books[], int nBook, user_t users[], int nUser) {
    int bookId, userId;
    printf("Nhap ID nguoi muon sach: ");
    scanf("%d", &userId);
    printf("Nhap ID sach muon muon: ");
    scanf("%d", &bookId);

    user_t* user = NULL;
    for (int i = 0; i < nUser; i++) {
        if (users[i].id == userId) {
            user = &users[i];
            break;
        }
    }
    if (user == NULL) {
        printf("Khong tim thay nguoi dung ID %d\n", userId);
        return;
    }

    Book* book = NULL;
    for (int i = 0; i < nBook; i++) {
        if (books[i].id == bookId) {
            book = &books[i];
            break;
        }
    }
    if (book == NULL) {
        printf("Khong tim thay sach ID %d\n", bookId);
        return;
    }
    if (book->is_borrowed) {
        printf("Sach nay da duoc muon!\n");
        return;
    }
    

    
    book->is_borrowed = 1;
    printf("Muon sach thanh cong!\n");
}

// Trả sách
void returnBook(Book books[], int nBook, user_t users[], int nUser) {
    int bookId, userId;
    printf("Nhap ID nguoi tra sach: ");
    scanf("%d", &userId);
    printf("Nhap ID sach tra: ");
    scanf("%d", &bookId);

    user_t* user = NULL;
    for (int i = 0; i < nUser; i++) {
        if (users[i].id == userId) {
            user = &users[i];
            break;
        }
    }
    if (user == NULL) {
        printf("Khong tim thay nguoi dung!\n");
        return;
    }

    
    for (int i = 0; i < nBook; i++) {
        if (books[i].id == bookId) {
            books[i].is_borrowed = 0;
            break;
        }
    }
    printf("Tra sach thanh cong!\n");
}
