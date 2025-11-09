
#ifndef user_h
#define user_h



typedef struct {
    int id;
    char name[50];
    
    
} user_t;

void addUser(user_t users[], int *n);
void editUser(user_t users[], int n);
void deleteUser(user_t users[], int *n);
void listUsers(user_t users[], int n);

#endif
