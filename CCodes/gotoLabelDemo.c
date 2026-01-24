#include<stdio.h>
int main(){
int i=1;
printf("Odd numbers between 1 to 10 are ");
odd:
if(i<=10)
{
printf("\n%d",i);
i+=2;
goto odd;
}
return 0;
}
