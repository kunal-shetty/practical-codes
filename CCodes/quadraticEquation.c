#include<stdio.h>
#include<math.h>
int main(){
float a,b,c,d1,d2,r1,r2;
printf("Enter the value of coefficients of x^2, x and constant\n");
scanf("%f%f%f",&a,&b,&c);
d1=b*b-4*a*c;
d2=sqrt(d1);
r1=(-b+d2)/(2*a);
r2=(-b-d2)/(2*a);
printf("Roots of the quadratic equation are %f and %f",r1,r2);
return 0;
}
