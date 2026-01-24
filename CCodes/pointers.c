#include<stdio.h>
void main(){
int a=10;
float b=5.5555;
char c='S';
int *p1=&a;
float *p2=&b;
char *p3=&c;
printf("Value of a(int) : %d, Address of a : %p\n",a,*p1);
printf("Value of b(float) : %f, Address of b : %p\n",b,*p2);
printf("Value of c(char) : %c, Address of c : %p",c,*p3);
}
