#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    printf("parent %d\n",getpid());
    for(int i = 0;i < 2;i++){
        pid = fork();
        if(pid == 0){
            printf("%d am child loop parent %d %d\n",getpid(),getppid(),i);
        }
    }
    while(wait(NULL) != -1);
    printf("%d %d\n",getpid() ,getppid());
    printf("success fully \n");
}