#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    int i = 0;

    pid = fork();
    if(pid > 0){
        int i = 1;
        printf("my copy of i is %d\n",i);
    }else{
        int i = 2;
        printf("my copy of i is %d\n",i);
    }
    return 0;
}