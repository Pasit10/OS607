#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t cpid;
    pid_t gcpid;

    cpid = fork();
    if(cpid == 0){
        gcpid = fork();
        if(gcpid == 0){
            printf("Can you see this3?\n");
            exit(0);
        }
        execlp("/bin/ls","ls",NULL);
        printf("can you see this2?\n");
        exit(0);
    }
    printf("can you see this1?\n");
    wait(NULL);
    printf("received child complete\n");
    exit(0);
    return 0;
}