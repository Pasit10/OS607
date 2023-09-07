#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void INThandler(int);

void main(){
    signal(SIGINT,INThandler);

    while(1)
        pause();
}

void INThandler(int sig){
    signal(sig,SIG_IGN);
    printf("Did you hit Ctrl-C?\n want to quit? [y/n]: \n");
    char c;
    scanf("%C",&c);
    if(c == 'y' || c == 'Y'){
        exit(0);
    }else
        signal(SIGINT,INThandler);
}