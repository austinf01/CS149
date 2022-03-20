#include <stdio.h>

int main(void) {
    const int NUM_ELEMENTS = 20;
    int userValues[NUM_ELEMENTS]; //Set of data specified by the user

    int numInputs;
    scanf("%d", &numInputs);
    for (int i = 0; i < numInputs; i++){
        scanf("%d",&userValues[i]);
    }

    int threshold;
    scanf("%d", &threshold);
    for(int i = 0; i < numInputs; i++){
        if (userValues[i] < threshold)
            printf("%d, ", userValues[i]);
    }

    return 0;
}