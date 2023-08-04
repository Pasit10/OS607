#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid,pidsub;
    int i,j;
    printf("only parent befor fork\n");
    for(i = 0;i < 5;i++){
        pid = fork();
        if(pid == 0){
            if((i % 2) == 0){
                printf("I am the child no %d\n",i);
                int num_gc = 3; //
                for(j = 0;j < num_gc;j++){
                    pidsub = fork(); //
                    if(pidsub == 0){
                        printf("I am grandchild num %d of even child no %d\n",j,i);
                        exit(0); //
                    }
                }
                while(wait(NULL) != -1); //
                exit(0);
            }else{
                printf("I am the child no %d\n",i);
                int num_gc = 4; //
                for(j = 0;j < num_gc;j++){
                    pidsub = fork(); //
                    if(pidsub == 0){
                        printf("I am grandchild num %d of odd child no %d\n",j,i);
                        exit(0); //
                    }
                }
                while(wait(NULL) != -1);
                exit(0); //
            }
            // exit(0);
        }
    }
    while(wait(NULL) != -1);
    return 0;
}