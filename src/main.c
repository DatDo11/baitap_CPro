#include <stdio.h>
#include "book/book.h"
#include "user/user.h"
#include "management/management.h"
#include "utils/utils.h"

#define MAX_BOOKS 100
#define MAX_USERS 100

int main() {
    Book books[MAX_BOOKS];
    user_t users[MAX_USERS];
    int nBook = 0, nUser = 0;
    int choice;

    while (1) {
        printf("\n===== MENU QUAN LY THU VIEN =====\n");
        printf("1. Them sach\n");
        printf("2. Sua thong tin sach\n");
        printf("3. Xoa sach\n");
        printf("4. Xem danh sach sach\n");
        printf("5. Them nguoi dung\n");
        printf("6. Sua thong tin nguoi dung\n");
        printf("7. Xoa nguoi dung\n");
        printf("8. Xem danh sach nguoi dung\n");
        printf("9. Muon sach\n");
        printf("10. Tra sach\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &nBook);
                break;
            case 2:
                editBook(books, nBook);
                break;
            case 3:
                deleteBook(books, &nBook);
                break;
            case 4:
                listBook(books, nBook);
                break;
            case 5:
                addUser(users, &nUser);
                break;
            case 6:
                editUser(users, nUser);
                break;
            case 7:
                deleteUser(users, &nUser);
                break;
            case 8:
                listUsers(users, nUser);
                break;
            case 9:
                borrowBook(books, nBook, users, nUser);
                break;
            case 10:
                returnBook(books, nBook, users, nUser);
                break;
            case 0:
                printf("Exit ...\n");
                return 0;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    }
    return 0;
}
