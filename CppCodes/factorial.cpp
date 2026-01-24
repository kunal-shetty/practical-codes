#include<stdio.h>
int factorial(int num);
int main(){
	int num;
	printf("Enter a number : ");
	scanf("%d",&num);
	int res = factorial(num);
	printf("Factorial of %d is %d", num, res);
	return -1;
}
int factorial(int num){
	if(num == 0)
	return 1;
	else
	return num * factorial(num - 1);
}