#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int pid;
    for (int i = 0 ; i < 2; i++) {
        pid = fork();
        if (pid == 0){
            printf("hello world from %d\n", getpid());
            exit(0);
        }
        else{
            wait(NULL);
            printf("hello world from %d\n",getpid());
        }
    }

    return 0;
}
