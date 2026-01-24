#include<stdio.h>
void main(){
	int i,j,rows;
	rows = 10;
	for(i=0;i<rows;i++){
		for(j=0;j<rows;j++){
			if(i==0 || j==0 ||i==rows-1 || j==rows-1)
			printf("* ");
			else
			printf("  ");
		}
		printf("\n");
	}
}
