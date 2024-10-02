#include<stdio.h>
int main(){
int n,rev_num=0;
printf("Enter the number to be reversed");
scanf("%d",&n);
while(n!=0){
rev_num=rev_num*10+n%10;
n/=10;
}
printf("\nReversed number is %d",rev_num);
return 0;
}
