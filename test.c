#include <stdio.h>

char *getString(char* str){
    str[] = "Will I be printed?";
    return str;
}

int main()
{
    char *str = {};
    printf("%s", getString(str));
    getchar();    
}