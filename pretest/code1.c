/*
    1. code สร้าง process กี่ตัว (รวม parent child)
    2. print helloworld จาก helloworld.c กี่ครั้ง
    3. print success กี่ครั้ง
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int count = 0;
    for(int i = 0;i < 3;i++){
        pid = fork();
        if(pid == 0){
            execlp("pretest/helloworld","./helloworld",NULL); // run helloworld.c
            printf("man\n");
        }else{
            pid = fork();
        }
    }
    while(wait(NULL) != -1);
    printf("success\n");
    return 0;
}

/* helloworld.c
    #include<stdio.h>

    int main(){
        printf("helloworld\n");
        return 0;
    }
*/