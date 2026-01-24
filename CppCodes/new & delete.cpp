#include<iostream>
using namespace std;
class MyClass{
	public:
		int x;
		MyClass(double val) : x(val){
			cout<<"Constructor called for MyClass with value : "<<x<<endl;
		}
		~MyClass(){
			cout<<"Destructor called for MyClass with value : "<<x<<endl;
		}
		void *operator new(size_t size){
			cout<<"Operator new operator called, size = "<<size<<endl;
			void *ptr = ::operator new(size);
			return ptr;
		}
		void operator delete(void *pointer){
			cout<<"Overloaded delete operator called"<<endl;
			::operator delete(pointer);
		}
};
int main(){
	MyClass *obj1 = new MyClass(2.0);
	MyClass *obj2 = new MyClass(4.2);
	delete obj1;
	delete obj2;
	return 0;
}