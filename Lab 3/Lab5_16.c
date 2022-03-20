#include <stdio.h>

int main(void){
    const int NUM_ELEMENTS = 20; //Number of input integers
    int uservals[NUM_ELEMENTS];  //Array to hold the user's input integers

    int numInputs;
    scanf("%d", &numInputs);
    for (int i = 0; i < numInputs; i++){
        scanf("%d",&uservals[i]);
    }

    for(int i = numInputs - 1; i >= 0; i--){
        printf("%d, ", uservals[i]);
    }

    return 0;
}