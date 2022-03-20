#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int argc, char *argv[]){

    int x, add;
    int y = strtol(argv[argc-1], NULL, 10);		//converts pointer of argc - 1 to a integer value
    int columnNum = 0;
    int sum = 0;
    char buffer[100];				                    //stores string of remaining line and placeholder for pipe i/o

    int fd[argc][2];
    pid_t p;

    //initialize pipe
    for(int i = 1; i < argc-1; i++){
        if (pipe(fd[i]) == -1){
            fprintf(stderr,"Pipe Failed");
            return 1;
        }
    }

    for (int i = 1 ; i < argc-1; i++) {
        p = fork();
        //child process
        if (p == 0){
            FILE *fp = fopen(argv[i],"r");
            if (fp == NULL){
                sum = 0;                               //set sum to 0
                sprintf(buffer, "%d", sum);              //write 0 into file descriptor
                write(fd[i][1], buffer, 100);            //to avoid read error
                close(fd[i][1]);                       //close writing
                printf("range %d: cannot open file\n", i);
                exit(1);
            }else{
                if (y > 0){
                    while(fscanf(fp, "%d", &x) == 1){		//checks value of each input
                                                            //separated by whitespaces
                        if (x > -1){
                            sum += x;
                        }else{
                            fprintf(stderr, "Warning- Value %d found.\n", x);   //prints values less than 0
                        }
                        columnNum++;		    			//increments z after each value is checked
                                                    //z helps to tracks column number
                        if (columnNum == y){				//max column value is reached
                            columnNum = 0;
                            fgets(buffer,100,fp);		//skips to next line
                        }
                    }
                }
                sprintf(buffer, "%d", sum);
                fclose(fp);                            //close file fp
                write(fd[i][1], buffer, 100);            //write into file descriptor
                close(fd[i][1]);                       //close writing
                exit(0);                               //stop child from running further
            }
        }
        //parent process
        else{
            //continues to rest of the program
        }
    }

    while(wait(NULL) != -1) {
        for (int i = 1 ; i < argc-1; i++) {
            if (read(fd[i][0], buffer, 100) != -1){     //read file descriptor
                close(fd[i][0]);                //close reading
                add = strtol(buffer, NULL, 10);
                sum += add;
            }
        }
    }

    if (argc > 2)
        fprintf(stdout,"Sum: %d\n", sum);
    return 0;
}
