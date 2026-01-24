#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream sourcee("input.txt");
	ofstream desti("output.txt");
	if(sourcee.is_open())
		cout<<"Source File Opened"<<endl;
	else {
		cout<<"Unable to Open Source File"<<endl;
		return 1;
	}
	if(desti.is_open())
		cout<<"Destination File Opened"<<endl;
	else {
		cout<<"Unable to Open Destination File"<<endl;
		return 1;
	}
	string line;
	while(getline(sourcee, line))
		desti<<line<<endl;
	cout<<"\nFile Copied Successfully !!!";
	sourcee.close();
	desti.close();
	return 0;
}