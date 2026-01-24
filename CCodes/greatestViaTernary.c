#include<stdio.h>
int main(){
int n1,n2,n3;
printf("Enter the numbers\n");
scanf("%d%d%d",&n1,&n2,&n3);
int max12=(n1>n2)?n1:n2;
int max123=(max12>n3)?max12:n3;
printf("Greatest of the three numbers is %d",max123);
return 0;
}
