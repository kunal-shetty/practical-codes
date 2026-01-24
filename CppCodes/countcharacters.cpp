#include<iostream>
using namespace std;
int main(){
	string input = "Hello World ";
	int count = 0;
	for(int i = 0; i < input.length(); i++){
		if(input[i] == ' ')
		continue;
		count++;
	}
	cout<<"Number of characters excluding whitespaces : "<<count;
	return 0;
}
