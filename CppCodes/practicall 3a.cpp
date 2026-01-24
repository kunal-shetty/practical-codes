#include <iostream>
#include <string>
using namespace std;
class Student {
	private:
	string name;
	int roll_no;
	public:
	void setDetails(string studentName, int studentRollNo) {
		name = studentName;
		roll_no = studentRollNo;
	}
	void displayDetails() {
		cout << "Student Name: "<<name << endl;
		cout << "Roll Number: " << roll_no << endl;
	}
};
int main() {
	Student s1; 
	string name;
	int rollNo;
	cout << "Enter the student's name: ";
	getline(cin, name);
	cout << "Enter the student's roll number: ";
	cin >> rollNo;
	s1.setDetails(name, rollNo);
	cout<<"\nStudent Details:\n";
	s1.displayDetails();
	return 0;
}
