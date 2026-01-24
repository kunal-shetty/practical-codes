#include<iostream>
using namespace std;
class Person{
	string name;
	int age;
	public:
	Person(string name, int age){
		this->name= name;
		this->age = age;
	}
	void displayDetails() const{
		cout<<"Name : "<<name<<", Age : "<<age<<endl;
	}
	Person *findEldest(Person *otherPerson){
		if(this->age > otherPerson->age)
		return this;
		return otherPerson;
	}
};
int main(){
	Person p1("John",25);
	cout<<"Person 1 - ";
	p1.displayDetails();
	Person p2("Alice",30);
	cout<<"Person 2 - ";
	p2.displayDetails();
	Person *eldest = p1.findEldest(&p2);
	cout<<"\nEldest Person : ";
	eldest->displayDetails();
	return 0;
}
