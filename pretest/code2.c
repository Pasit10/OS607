#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    for (int i = 0; i < 2; i++){
        pid = fork();
        if(pid==0){ // child
            printf("Hello world\n");
            pid = fork();
        }
        else{
            printf("momy\n");
        }
        wait(NULL);
    }
    while(wait(NULL)!=-1);
    printf("success\n");
    return 0;
}