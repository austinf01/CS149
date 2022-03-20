#include <stdio.h>

int main(void){
    const int NUM_ELEMENTS = 20; //Number of input integers
    int uservals[NUM_ELEMENTS];  //Array to hold the user's input integers
    int numInputs;
    int lowerBound,upperBound;

    scanf("%d", &numInputs);
    for (int i = 0; i < numInputs; i++){
        scanf("%d",&uservals[i]);
    }

    scanf("%d %d",&lowerBound,&upperBound);

    for (int i = 0; i < numInputs; i++){
        if (uservals[i] >= lowerBound && uservals[i] <= upperBound)
            printf("%d,",uservals[i]);
    }

    return 0;
}
