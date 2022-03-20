#include <stdio.h>

int main(void) {
   int baseInt;
   int headInt;
   
   baseInt = 0;
   headInt = 1;

   printf("    %d\n",headInt);
   printf("    %d%d\n",headInt);
   for (int i = 0; i < 4; i++)
    printf("%d",baseInt);
   for (int i = 0; i < 3; i++)
    printf("%d",headInt);
   printf("\n");
   for (int i = 0; i < 4; i++)
    printf("%d",baseInt);
   for (int i = 0; i < 4; i++)
    printf("%d",headInt);
   printf("\n");
   for (int i = 0; i < 4; i++)
    printf("%d",baseInt);
   for (int i = 0; i < 3; i++)
    printf("%d",headInt);  
   printf("\n");
   printf("    %d%d\n",headInt);
   printf("    %d\n",headInt);

   return 0;
}