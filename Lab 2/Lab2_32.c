#include <stdio.h>

int main(void) {
    int currentPrice;
    int lastMonthsPrice;

        printf("Enter the current price and then last month's price:\n");
        scanf("%d", &currentPrice);
        scanf("%d", &lastMonthsPrice);
        printf("This house is $%d ", currentPrice);
        printf("The change is $%d since last month. \n", currentPrice - lastMonthsPrice);
        printf("The estimated monthly mortgage is $%0.6f", (currentPrice*0.051)/12);

    return 0;

}