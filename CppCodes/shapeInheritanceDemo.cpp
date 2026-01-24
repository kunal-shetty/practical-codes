#include<iostream>
using namespace std;
class Shape{
	public:
	virtual void draw(){
		cout<<"Drawing Shape"<<endl;
	}
};
class Circle:public Shape{
	public:
	void draw() override{
		cout<<"Drawing Circle"<<endl;
	}
};
class Rectangle:public Shape{
	public:
	void draw() override{
		cout<<"Drawing Rectangle"<<endl;
	}
};
int main(){
	Shape *shape1;
	Circle c; Rectangle r;
	shape1 = &c; shape1->draw();
	shape1 = &r; shape1->draw();
	return 0;
}
