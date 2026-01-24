#include<stdio.h>
int hcf(int a,int b){
	int count=1,temp;
	while(1){
		if(a%count==0 && b%count==0)
		temp=count;
		count++;
		if(count>a || count>b)
		break;
	}
	return temp;
}
int lcm(int a,int b){
	return (a*b)/hcf(a,b);
}
void main(){
	printf("%d\n",hcf(30,45));
	printf("%d",lcm(30,45));
}
