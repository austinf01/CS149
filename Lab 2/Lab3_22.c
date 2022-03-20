#include <stdio.h>
#include <limits.h>

int main(void) {
    int numbers[3];
    int min = INT_MAX;

    printf("Input three integers: \n");
    for (int i =0; i < 3; i++){
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 3; i++){
        if (numbers[i] < min)
            min = numbers[i];
    }

    printf("%d", min);
    
    return 0;
}