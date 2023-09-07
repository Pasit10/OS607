#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int notDone = 1; int cnt = 0;

void mySIGhandler(int sig){
    signal(SIGALRM,SIG_IGN);
    notDone = 0;
}

int main(void){
    signal(SIGALRM,mySIGhandler);
    pid_t pid = fork();
    if(pid == 0){
        // sleep(4);
        // printf("sending SIGALRM\n");
        // kill(getppid(),SIGALRM);
        // exit(0);
        //sleep(4);
        printf("child created\n");
        sleep(2);
        while(1)
            printf("this line should not br shown\n");
    }else{
        // printf("parent wait for SIGALRM\n");
        // while(notDone)
        //     cnt++;
        sleep(1);
        kill(pid,SIGKILL);
    }
    printf("it take %d\n",cnt);
    return 0;
}

/*  
    นายพสิษฐ์ มาลารัตน์ 65050607
    output:
        child created
        it take 0
*/