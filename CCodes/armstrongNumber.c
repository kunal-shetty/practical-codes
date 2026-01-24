#include<stdio.h>
int main(){
int num,rem,check=0;
printf("Enter your number\n");
scanf("%d",&num);
int temp=num;
while(num!=0){
rem=num%10;
num/=10;
check+=rem*rem*rem;
}
num=temp;
if(check==num)
printf("Armstrong's Number");
else
printf("Not an Armstrong's Number");
return 0;
}
