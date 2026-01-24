#include<iostream>
#include<vector>
using namespace std;
vector<int> primes;
void calcPrimes(int limit){
	int n = 2, i = 2;
	while(n < limit){
		bool isPrime = true;
		for(int i = 2; i < n; i++){
			if(n % i == 0) isPrime = false;
		}
		if(isPrime) primes.push_back(n);
		n++;
	}
}
int main(){
	calcPrimes(10000000);
	for(int i = 0; i < primes.size(); i++){
		cout<<primes.at(i)<<endl;
	}
	return 0;
}