#include<stdio.h>
int main(){
int n,fact=1,i=1;
printf("Enter your number\n");
scanf("%d",&n);
do{
fact*=i;
i++;
}while(i<=n);
printf("Factorial of the number is %d",fact);
return 0;
}
