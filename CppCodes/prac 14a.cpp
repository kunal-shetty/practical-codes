#include<iostream>
#include<stdexcept>
using namespace std;
int main(){
	try{
		int x = -1;
		if(x < 0) throw "Negative number error";
		if(x == 0) throw runtime_error("Zero error");
		if(x == -1) throw out_of_range("Out of range error");
		cout<<"x is positive"<<endl;
	}
	catch(const char *msg){
		cout<<"Caught exception (C-string) : "<<msg<<endl;
	}
	catch(const runtime_error &e){
		cout<<"Caught exception (runtime_error) : "<<e.what()<<endl;
	}
	catch(const out_of_range &e){
		cout<<"Caught exception (out_of_range) : "<<e.what()<<endl;
	}
	catch(const exception &e){
		cout<<"Caught exception (std::exception) : "<<e.what()<<endl;
	}
	catch(...){
		cout<<"Caught an unknown exception"<<endl;
	}
	return 0;
}