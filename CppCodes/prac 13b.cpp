#include<iostream>
#include<fstream>
using namespace std;
class Student{
	public:
	string name;
	int age;
	Student(string name = "", int age = 0){
		this->name = name;
		this->age = age;
	}
	void display() const{
		cout<<"Name : "<<name<<" , Age : "<<age<<endl;
	}
	void writeToFile(const string &filename){
		ofstream outFile(filename);
		if(outFile.is_open()){
			outFile<<name<<endl;
			outFile<<age<<endl;
			outFile.close();
			cout<<"Object saved to file."<<endl;
		} else{
			cout<<"Error opening file!"<<endl;
		}
	}
	void readFromFile(const string &filename){
		ifstream inFile(filename);
		if(inFile.is_open()){
			getline(inFile, name);
			inFile>>age;
			inFile.close();
			cout<<"Object read from file."<<endl;
		} else {
			cout<<"Error opening file!"<<endl;
		}
	}
};
int main(){
	Student s1("Alice",22);
	s1.writeToFile("student.txt");
	Student s2;
	s2.readFromFile("student.txt");
	s2.display();
	return 0;
}