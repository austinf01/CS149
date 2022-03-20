#include <stdio.h>

int main(void){
    const int NUM_ELEMENTS = 9;
    int uservals[NUM_ELEMENTS];  //Set of data specified by the user

    int numInputs;
    int i = 0;
    do{
        scanf("%d",&uservals[i]);
        i++;
        if (i > 10){
            printf("Too many numbers");
            return 1;
        }
    } while(uservals[i - 1] > 0);

    printf("Middle item:%d", uservals[i/2 - 1]);
    return 0;
}