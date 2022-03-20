#include <stdio.h>

int main(void) {
    
    int userNum, x;
        printf("Enter integer:\n");
        scanf("%d", &userNum);
        printf("Divide by: \n");
        scanf("%d", &x);
        printf("%d\n",userNum/x);
        printf("%d\n",userNum/x/x);
        printf("%d\n",userNum/x/x/x);
    return 0;
}