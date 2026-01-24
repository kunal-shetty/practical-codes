#include<stdio.h>
int main(){
int i,j;
printf("         *\n");
for(i=1;i<=5;i++){
for(j=5;j>i;j--){
printf("  ");
}
for(j=1;j<=2*i;j++){
printf("* ");
}
printf("\n");
}
return 0;
}
