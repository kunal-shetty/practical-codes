#include<iostream>
using namespace std;
int main(){
	int n, odd = 0, even = 0;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	for(int i = 1, count = 0; count < n; i += 2, count++ )
	odd = odd + i;
	cout<<"Sum of odd n natural numbers : "<<odd<<endl;
	for(int i = 2, count = 0; count < n; i += 2, count++ )
	even = even + i;
	cout<<"Sum of even n natural numbers : "<<even;
	return 0;
}
