#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    int x;
    int y = strtol(argv[argc-1],NULL, 10);		//converts pointer argv[2] to a integer value
    int i = 0;
    int sum = 0;
    char buffer[100];				//stores string of remaining line

    FILE *fp = fopen(argv[1],"r");
    if (fp == NULL){
        printf("cannot open file\n");
        exit(1);
    }
	if (y > 0){
        while(fscanf(fp, "%d", &x) == 1){		//checks value of each input 
                                                //separated by whitespaces
            if (x > -1){
                sum += x;
            }else{
                fprintf(stderr, "Warning- Value %d found.\n", x);
            }
            i++;					//increments i after each value is checked
                                    //i helps to tracks column number
            if (i == y){				//max column value is reached
                i = 0;
                fgets(buffer,100,fp);		//skips to next line
            }
        }
    }
    fprintf(stdout,"Sum: %d\n", sum);
    fclose(fp);

    return 0;
}