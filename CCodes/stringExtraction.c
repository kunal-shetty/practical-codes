#include<stdio.h>
void main(){
char str[100];
int start,end,i;
printf("Enter the string\n");
fgets(str,sizeof(str),stdin);
printf("Enter starting position : ");
scanf("%d",&start);
printf("Enter ending position : ");
scanf("%d",&end);
for(i=start-1;i<=end-1;i++)
printf("%c",str[i]);
}
