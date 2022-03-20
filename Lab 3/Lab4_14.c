#include <stdio.h>
#include <string.h>

int main(void) {
    int x;
    char filler[20];
    char rvsBin[20];
    scanf("%d", &x);
    while(x > 0){
        sprintf(filler,"%d",x%2);
        strcat(rvsBin, filler);
        x/= 2;
    }
    printf("%s",rvsBin);

    return 0;
}