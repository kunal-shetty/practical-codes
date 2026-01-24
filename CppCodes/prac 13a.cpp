#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	string abc = "abc.txt";
	string xyz = "xyz.txt";
	ifstream sourceFile("abc.txt");
	ofstream destinationFile("xyz.txt");
	if(!sourceFile.is_open()){
		cerr<<"Unable to open source file"<<endl;
		return 1;
	}
	if(!destinationFile.is_open()){
		cerr<<"Unable to open destination file"<<endl;
		return 1;
	}
	string line;
	while(getline(sourceFile, line)){
		destinationFile<<line<<endl;
	}
	sourceFile.close();
	destinationFile.close();
	
	cout<<"File copied successfully"<<endl;
	return 0;
}
