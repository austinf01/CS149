#include <stdio.h>

int main(void) {
   int userNum,userSecNum;
   
   printf("Enter integer:\n");
   scanf("%d", &userNum);
   printf("%d squared is %d\n",userNum,userNum*userNum);
   printf("And %d cubed is %d!!\n", userNum,userNum*userNum*userNum);
   printf("Enter another integer:\n");
   scanf("%d", &userSecNum);
   printf("%d + %d is %d\n",userNum,userSecNum,userNum+userSecNum);
   printf("%d * %d is %d",userNum,userSecNum,userNum*userSecNum);

   return 0;
}