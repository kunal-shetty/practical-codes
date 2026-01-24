#include<stdio.h>
#include<math.h>
void main(){
double num1,num2;
printf("Enter a number to find its square root\n");
scanf("%lf",&num1);
printf("Enter a number to find its absolute value\n");
scanf("%lf",&num2);
printf("Square of the number %lf is %lf\n",num1,sqrt(num1));
printf("Absolute value of %lf is %lf",num2,fabs(num2));
}
