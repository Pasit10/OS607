#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	char userChoide = 'z';
	while(userChoide != 'q'){
		printf("a : ls ");
		printf("b : ps ");
		printf("c : who ");
		printf("q for quit ");
		scanf(" %c", &userChoide);
		pid_t pid = fork();
		if(pid == 0){
			switch(userChoide){
				case 'a':
					execlp("/bin/ls","ls",NULL);
					break;
				case 'b':
					execlp("/bin/ps","ps",NULL);
					break;
				case 'c':
					execlp("/usr/bin/whoami","whoami",NULL);
					break;
				default:
					break;
				}
			exit(0);
		}
		wait(NULL);
	}
}
