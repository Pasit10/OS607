#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();

    int data = 0;

    if(pid == 0){
        sleep(1);
        data += 5;
    }else{
        data += 2;
    }

    data += 1;
    printf("%d\n",data);
    if(pid == 0){
        exit(-1);
    }
    while(wait(NULL) != -1);
    printf("success fully \n");
}