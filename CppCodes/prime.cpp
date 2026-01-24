#include<iostream>
using namespace std;
bool isprime(int num){
	for(int i = 2; i < num; i++){
		if(num %i == 0)
		return false;
}
	return true;
}
int main(){
	int n, count = 0;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	cout<<"Prime numbers upto "<<n<<" are"<<endl;
	for(int i = n; i > 1; i--){
  		if(isprime(i)){
			cout<<i<<" ";
			count++;
		}
	}
	cout<<"\nThere are "<<count<<" Prime numbers upto "<<n<<endl;
	return 0;
}
