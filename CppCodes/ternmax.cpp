#include<iostream>
using namespace std;
int main(){
	int n1,n2,n3;
	cout<<"Enter three numbers"<<endl;
	cin>>n1>>n2>>n3;
	int max = (n1>n2)?((n1>n3)?n1:n3):((n2>n3)?n2:n3);;
	cout<<"Greatest of the three numbers is : "<<max;
	return 0;
}
