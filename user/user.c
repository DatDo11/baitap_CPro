#include "user.h"
#include <stdio.h>
#include <string.h>


void addUser(user_t users[], int *n) {
    if (*n >= 20) {
        printf("Da dat toi so luong nguoi dung toi da!\n");
        return;
    }
    printf("Nhap ten nguoi dung: ");
    getchar();
    fgets(users[*n].name, 50, stdin);
    users[*n].name[strcspn(users[*n].name, "\n")] = 0;
    users[*n].id = *n + 1; 
    
    (*n)++;
    printf("Them nguoi dung thanh cong!\n");
}


void editUser(user_t users[], int n) {
    int id, found = 0;
    printf("Nhap ID nguoi dung muon sua: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (users[i].id == id) {
            found = 1;
            printf("Nhap ten nguoi dung moi (de trong neu khong doi): ");
            getchar();
            char input[50];
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n') {
                input[strcspn(input, "\n")] = 0;
                strcpy(users[i].name, input);
            }
            printf("Sua ten nguoi dung thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay nguoi dung co ID %d\n", id);
    }
}


void deleteUser(user_t users[], int *n) {
    int id, found = 0;
    printf("Nhap ID nguoi dung muon xoa: ");
    scanf("%d", &id);

    for (int i = 0; i < *n; i++) {
        if (users[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                users[j] = users[j + 1];
            }
            (*n)--;
            printf("Da xoa nguoi dung co ID %d\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay nguoi dung co ID %d\n", id);
    }
}


void listUsers(user_t users[], int n) {
    printf("Danh sach nguoi dung:\n");
    printf("%-5s %-25s \n", "ID", "Ten");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-25s \n", users[i].id, users[i].name );
    }
}
