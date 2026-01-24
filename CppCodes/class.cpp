#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int roll_no;

public:
    void setDetails(string student_name, int student_roll_no) {
        name = student_name;
        roll_no = student_roll_no;
    }
    void display() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
    }
};

int main() {
    Student student1;

    student1.setDetails("Kunal", 3773);
    student1.display();

    return 0;
}

