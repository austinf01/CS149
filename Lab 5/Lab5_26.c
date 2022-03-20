#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void){
    char s[50];
    bool run = true;
    do{
        fgets(s,50,stdin);
        s[strlen(s) -1] = '\0';
        if (strcmp("Done",s) == 0 || strcmp("done",s) == 0 || strcmp("d",s) == 0)
            break;
        for(int i = strlen(s); i > -1; i--){
            printf("%c",s[i]);
        }
        printf("\n");
    }while(run);
    return 0;
}