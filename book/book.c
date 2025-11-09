#include <stdio.h>
#include <book.h>
#include <string.h>

void addBook(Book books[],int *n){
    printf("Nhap ten sach :\n");
    getchar();
    fgets(books[*n].title,99,stdin);
    printf("Nhap ten tac gia :\n");
    fgets(books[*n].author,99,stdin);
    books[*n].id = *n+1;
    books[*n].is_borrowed = 0;
    (*n)++;
}

void deleteBook(Book books[], int *n) {
    int id, found = 0;
    printf("Nhap ID sach muon xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            printf("Da xoa sach co ID %d\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ID %d\n", id);
    }
}

void editBook(Book books[], int n) {
    int id, found = 0;
    printf("Nhap ID sach muon sua: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("Nhap tieu de moi : ");
            getchar(); ;
            char input[100];
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n') {
                input[strcspn(input, "\n")] = 0; 
                strcpy(books[i].title, input);
            }

            printf("Nhap ten tac gia moi : ");
            getchar(); ;
            char input2[100];
            fgets(input2, sizeof(input2), stdin);
            if (input[0] != '\n') {
                input2[strcspn(input2, "\n")] = 0;
                strcpy(books[i].author, input2);
            }

            printf("Sua thong tin sach thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ID %d\n", id);
    }
}

void listBook(Book books[], int n) {
    printf("Danh sach cac sach trong thu vien:\n");
    printf("%-5s %-30s %-20s %-10s\n", "ID", "Tieu de", "Tac gia", "Trang thai");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-30s %-20s %-10s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].is_borrowed ? "Da muon" : "Con trong");
    }
}
