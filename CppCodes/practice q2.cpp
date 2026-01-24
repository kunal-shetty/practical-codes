#include<iostream>
using namespace std;
int main(){
	for(int i = 0; i < 5; i++){
		char letter = 'A';
		for(int j = 0; j <= i; j++){
			cout<<letter;
			letter++;
		}
		cout<<endl;
	}
	return 0;
}