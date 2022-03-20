#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int x;
    int counter = 0;
    int max = 0;
    double sum, average;
    char s[100];
    fgets(s,100,stdin);
    //tokenize the string, splitting after each whitespace
    char * token = strtok(s," ");
    while (token != NULL){
        x = atoi(token);        //converts string to int
        if (x < 0)
            break;
        sum += x;
        if (x > max)
            max = x;
        counter++;
        token = strtok(NULL, " ");  //continues to tokenize string
                                    //after last string, returns NULL
    }
    average = sum / counter;
    printf("%d ", max);
    printf("%0.2f\n",average);

    return 0;
}