#include<iostream>
using namespace std;
void swap(int &a,int &b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
int main(){
	int num1 = 2, num2 = 4;
	cout<<"Before swap : "<<num1<<" "<<num2<<endl;
	swap(num1,num2);
	cout<<"After swap : "<<num1<<" "<<num2<<endl;
	return 0;
}