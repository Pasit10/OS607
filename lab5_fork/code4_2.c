#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int sum = 0;
int main(){
    pid_t pid;
    int i;
    if((pid = fork()) > 0){
        i = 1;
        sum += i;
        printf("I am parent. My id is %d\n",getpid());
    }else{
        i = 2;
        sum += i;
        printf("I am child. My id is %d\n",getpid());
        printf("My parent id is %d\n",getppid());
        exit(0);
    }
    wait(NULL);
    printf("(parent) sum = %d\n",sum);
    return 0;
}