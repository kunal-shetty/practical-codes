#include<iostream>
#include<string>
using namespace std;
int main(){
	string str, reversedStr;
	cout<<"Enter String to be Reversed : ";
	cin>>str;
	int len = str.length();
	for(int i = str.length() - 1; i >= 0; i--)
		reversedStr += str[i];
	cout<<"Original String : "<<str<<endl;
	cout<<"Reversed String : "<<reversedStr<<endl;
	bool isPalindrome = str == reversedStr;
	if(isPalindrome)
	cout<<"String entered is a palindrome";
	else
	cout<<"String entered is not a palindrome";
	return 0;
}