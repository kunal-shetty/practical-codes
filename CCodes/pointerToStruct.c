#include<stdio.h>
void main(){
	int a = 10;
	int *p = &a;
	char b = 'S';
	char *ptr = &b;
	printf("%d  %p\n",a,p);
	printf("%d  %p\n",a,p);
	ptr++;
	printf("%c  %p\n",b,ptr);
	if(*ptr==*p)
	printf("1\n");
	ptr--;
	
	printf("p : %d\nptr : %c\n",*p,*ptr);
	printf("b : %c\n",b);
	printf("mem : %p",&b);
}
