#include<stdio.h>
int main(){
int fact,n;
printf("Enter a number\n");
scanf("%d",&n);
if(n<0)
printf("Invalid input");
else{
fact=factorial(n);
printf("Factorial of the number is %d",fact);
}
return 0;
}
int factorial(int n){
if(n==0||n==1)
return 1;
else 
return n*factorial(n-1);
}
