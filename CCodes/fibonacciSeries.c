#include<stdio.h>
int main(){
int n,t1=0,t2=1,t,i;
printf("Enter the number of terms to display\n");
scanf("%d",&n);
printf("\nFibonacci series\n");
for(i=1;i<=n;i++){
printf("%d ",t1);
t=t1+t2;
t1=t2;
t2=t;
}
return 0;
}
