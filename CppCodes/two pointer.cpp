#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cout<<"Enter string to check : ";
	cin>>str;
	int length = str.length();
	int i = 0, j = length - 1;
	while(i < j){
		if(!(str[i]==str[j])){
			cout<<"Not a palindrome";
			return 0;
		}
		i++; j--;
	}
	cout<<"Palindrome";
	return 0;
}