#include <stdio.h>
#include <string.h>
#include <ctype.h>


char s[50];
char answer[50];

void RemoveNonAlpha(char userString[], char userStringAlphaOnly[]){
    
    int j = 0;

    for(int i = 0; i < strlen(userString); i++){
        if(isalpha(userString[i])){
            userStringAlphaOnly[j] = userString[i];
            j++;
        }
    }

}

int main(void){
    fgets(s,50,stdin);
    RemoveNonAlpha(s,answer);
    printf("%s",answer);
    return 0;
}