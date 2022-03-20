#include <stdio.h>
#include <string.h>

int main(void){
    const int NUM_ELEMENTS = 20;                    //Number of input integers
    const int STR_LENGTH = 100;                     //String length in arr
    char uservals[NUM_ELEMENTS][STR_LENGTH];        //Array to hold the user's input integers
    char searchCharacter;                           //character to find words in list 
    int numInputs;
   
    scanf("%d", &numInputs);
    for (int i = 0; i < numInputs; i++){
        scanf("%s",uservals[i]);
    }

    scanf(" %c", &searchCharacter);

    for (int i = 0; i < numInputs; i++){
        if(strchr(uservals[i], searchCharacter) != NULL)    //filters words without "searchCharacter"
            printf("%s, ",uservals[i]);
    }
    return 0;
}
