#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    char s[100];
    char buffer[50];
    char *token;
    int row = 0;
    int column;
    pid_t pid, p;
    int status;
    char *buf2[20];

    FILE *fp = fopen(argv[1],"r");
    if (fp == NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    while(fgets(s,100,fp)){                         //gets line of file fp
        s[strcspn(s,"\n")] = 0;                     //removes newline from fgets
        token = strtok(s," ");                      
        column = 0;                                 
        while(token != NULL){		                //parse strings separated by spaces from fgets line
            buf2[column] = token;
            column++;
            token = strtok(NULL," ");             
        }
        buf2[column++] = NULL;                      //last argument for execvp must be NULL
        row++;                                      //increment row
        p = fork();                                 //create child process
        //Child process
        if (p == 0){ 
            pid = getpid();
            sprintf(buffer,"%d.out",pid);
            int file = open(buffer, O_RDWR | O_CREAT | O_APPEND , 0777);            //returns fd for currentpid.out
            dup2(file,1);                                                           //stdout is fd[1], so we use 1 for dup2
            sprintf(buffer,"%d.err",pid);
            int file2 = open(buffer, O_RDWR | O_CREAT | O_APPEND, 0777);
            dup2(file2,2);                                                           //stderr is fd[2], so we use 2 for dup2
            close(file);
            close(file2);
            printf("Starting command %d: child %d pid of parent %d\n", row, pid, getppid());    //row is command #
            fflush(stdout);
            execvp(buf2[0], buf2);                                                   //runs new process buf[0] ... 
            perror(buf2[0]);                                                         //error with command name
            exit(2);
        }
    }
    while ((pid = wait(&status)) > 0) {
        sprintf(buffer,"%d.out",pid);
        int file = open(buffer, O_RDWR | O_CREAT | O_APPEND , 0777);                //returns fd for currentpid.out
        dup2(file,1);                                                               //stdout is fd[1], so we use 1 for dup2
        sprintf(buffer,"%d.err",pid);
        int file2 = open(buffer, O_RDWR | O_CREAT | O_APPEND, 0777);
        dup2(file2,2);                                                              //stderr is fd[2], so we use 2 for dup2
        close(file);
        close(file2);
        printf("Finished child %d of parent %d\n", pid, getpid());
        fflush(stdout);
        if (WIFEXITED(status)) {
            fprintf(stderr,"Exited with exitcode = %d\n",WEXITSTATUS(status));      //exited with exitcode 0 for success in stderr
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr,"Killed with signal %d\n", WTERMSIG(status));            //prints kill signal to stderr
        }
    }

    return 0;
}