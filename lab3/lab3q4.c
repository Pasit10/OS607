#include<stdio.h>

int main(){
	double sum,count;
	double input;
	count = 0,sum = 0;
	printf("input number : ");
	scanf("%lf",&input);
	while(input > 0){
		sum += input;
		count++;
		printf("input number : ");
		scanf("%lf",&input);
	}
	printf("sum is %.2f\n",sum);
	printf("avg is %.2f\n",sum / count);
}
