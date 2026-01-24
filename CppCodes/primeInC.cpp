#include<stdio.h>
char main(){
	int i = 2, num;
	printf("Enter your number : ");
	scanf("%d",&num);
	for(i = 2; i < num / 2; i++){
		if(num % i == 0){
			printf("Not a prime number");
			return 'S';
		}
	}
	printf("Prime number");
	return 'S';
}