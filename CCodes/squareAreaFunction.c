#include<stdio.h>
int areacalc(int side){
return side*side;
}
int main(){
int side,area;
printf("Enter the value of side of square\n");
scanf("%d",&side);
area=areacalc(side);
printf("Area of square is %d",area);
return 0;
}
