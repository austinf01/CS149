#include <stdio.h>

int main(void) {
    char userName[50];

    printf("Enter your first name:\n");
    scanf("%s", userName);
    printf("Hello %s, and welcome to CS Online!", userName);

    return 0;
}