#include<stdio.h>
int main(){
int i,roll_no[10];
char names[10][50];
for(i=0;i<10;i++){
printf("\nEnter Roll no. for student no. %d : ",i+1);
scanf("%d",&roll_no[i]);
printf("\nEnter name of the student : ");
scanf("%s",&names[i]);
}
for(i=0;i<10;i++){
printf("Roll no. : %d and Name : %s\n",roll_no[i],names[i]);
}
return 0;
}
