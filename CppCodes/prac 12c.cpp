#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;
int main(){
	string str1;
	cout<<"Enter a string : ";
	getline(cin,str1);
	int length = str1.length();
	cout<<"Length of the string : "<<length<<endl;
	ofstream fout("output.txt");
	if(fout.is_open()){
		fout<<str1;
		fout.close();
		cout<<"String successfully stored in file output.txt"<<endl;
	}
	else{
		cout<<"Unable to open file for writing!"<<endl;
		return 1;
	}
	ifstream fin("output.txt");
	string fetchedString;
	if(fin.is_open()){
		getline(fin, fetchedString);
		fin.close();
		cout<<"String fetched from file : "<<fetchedString<<endl;
	}
	else{
		cout<<"Unable to open file for reading! "<<endl;
		return 1;
	}
	
	string concatStr = str1 + " Concatenated";
	cout<<"Concatenated String : "<<concatStr<<endl;
	
	int i = 3;
	int len2 = 5;
	string str2 = str1.substr(i,len2);
	cout<<"Substring from index "<<i<<" with length "<<len2<<" "<<str2<<endl;
	
	string str3 = "is";
	size_t found = str1.find(str3);
	if(found != string::npos){
		cout<<"Substring "<<str3<<" found at index "<<found<<endl;
	}
	else{
		cout<<"Substring "<<str3<<" not found!"<<endl;
	}
	
	transform(str1.begin(),str1.end(),str1.begin(), ::toupper);
	cout<<"Uppercase String : "<<str1<<endl;
	transform(str1.begin(),str1.end(),str1.begin(), ::tolower);
	cout<<"Lowercase String : "<<str1<<endl;
	
	string revStr = str1;
	reverse(revStr.begin(),revStr.end());
	cout<<"Reversed string : "<<revStr<<endl;
	
	string str4 = "Hello";
	if(str1 == str4)
	cout<<"The strings are identical."<<endl;
	else
	cout<<"The strings are not identical"<<endl;
	str1 = "Hello World";
	string toReplace = "World";
	string replacement = "C++";
	size_t pos = str1.find(toReplace);
	if(pos != string::npos){
		str1.replace(pos, toReplace.length(), replacement);
		cout<<"String after replacement : "<<str1<<endl;
	}
	else
	cout<<"Substring "<<toReplace<<" not found for replacement "<<endl;
	
	str1.erase(0,str1.find_last_not_of("\t"));
	str1.erase(str1.find_last_not_of("\t") + 1);
	cout<<"Trimmed string : "<<str1<<endl;
	
	return 0;
}
