#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int csum;
void *runner(void *param);

int main(int argc,char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid,&attr,runner,argv[1]);
    //pthread_join(tid,NULL);


    int msum = 0;
    int input = atoi(argv[1]);
    for(int i = 0;i < input;i++){
        msum += i;
        sleep(0.1);
        printf("%d\n",csum);
    }
    printf("difference csum and msum %d\n",csum - msum);

    return 0;
}

void *runner(void *param){
    int upper = atoi(param);
    int i;
    csum = 0;
    if(upper > 0){
        for(i = 1;i <= upper*2;i++){
            sleep(0.01);
            csum += i;
        }
    }
    pthread_exit(0);
}