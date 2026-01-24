#include<iostream>
using namespace std;
int main(){
	bool isPrime = true;
	int n;
	cout<<"Enter a number : ";
	cin>>n;
	if(n < 2){
		cout<<n<<" is neither a Prime nor Composite";
		return 0; 
	}
	for(int i = 2; i < n / 2; i++)
		if(n % i == 0)
		isPrime = false;
	
	string result = (isPrime)?"":" not";
	cout<<n<<" is"<<result<<" a Prime number";
	return 0;
}