#include<iostream>
#include<stdexcept>
using namespace std;
void test(){
	try {
		int numerator = 10;
		int denominator = 0;
		if(denominator == 0){
			throw runtime_error("Divide by zero error");
		}
		int result = numerator / denominator;
		cout<<"Result : "<<result<<endl;
	}
	catch(const runtime_error &e){
		cout<<"Caught exception in test function : "<<e.what()<<endl;;
		throw;
	}
}
int main(){
	try {
		test();
	}
	catch(const runtime_error &e){
		cout<<"Caught rethrown exception in main : "<<e.what()<<endl;
	}
	return 0;
}