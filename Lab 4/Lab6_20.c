#include <stdio.h>

    double LapsToMiles(double userLaps){
        return userLaps * 0.25;
    }

int main(void){

    double userLaps;
    printf("enter number of laps: ");
    scanf("%lf", &userLaps);
    printf("%0.2f\n", LapsToMiles(userLaps));

    return 0;
}