#include<iostream>
using namespace std;
int main(){
	for(int i = 0; i < 5; i++){
		int num = (i % 2 == 1) ? 0 : 1;
		for(int j = 0; j <= i; j++){
			cout<<num;
			num = 1 - num;
		}
		cout<<endl;
	}
	return 0;
}