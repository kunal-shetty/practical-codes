#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter your number : ";
	cin>>num;
	cout<<((num & 1) ? "Odd" : "Even");
	return 0;
}