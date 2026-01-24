#include<stdio.h>
#include<string.h>
int iseven(int n);
int isodd(int n);
void main(){
	int n=7;
	iseven(n);
}

int iseven(int n){
	if(n%2==0)
	return !isodd(n);
	printf("ODD");
	return 0;
}
int isodd(int n){
	if(n%2!=0)
	return !iseven(n);
	printf("EVEN");
	return 0;
}
