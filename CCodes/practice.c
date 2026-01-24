#include<stdio.h>
int factorial(int n){
	if(n==0 || n==1)
	return 1;
	return n*factorial(n-1);
}
int main(){
	int n=5;
	int fact=factorial(5);
	printf("Factorial : %d",fact);
	return 0;
}
