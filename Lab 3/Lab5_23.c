#include <stdio.h>
#include <limits.h>

int main(void){
    const int NUM_ELEMENTS = 20; //Number of input integers
    int uservals[NUM_ELEMENTS];  //Array to hold the user's input integers
    int numInputs;
    int min = INT_MAX;
    int secondMin = INT_MAX;

    scanf("%d", &numInputs);
    for (int i = 0; i < numInputs; i++){
        scanf("%d",&uservals[i]);
    }

    for (int i = 0; i < numInputs; i++){
        if (uservals[i] < min)
            min = uservals[i];
    }

    for (int i = 0; i < numInputs; i++){
        if (uservals[i] < secondMin && uservals[i] > min)
            secondMin = uservals[i];
    }

    printf("%d and %d", min, secondMin);

    return 0;
}