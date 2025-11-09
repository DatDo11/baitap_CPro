#include "utils.h"
#include <stdio.h>

int getInt(const char *msg) {
    int value;
    printf("%s", msg);
    scanf("%d", &value);
    return value;
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
