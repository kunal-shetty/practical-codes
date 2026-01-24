/*
#include <iostream>
#include <typeinfo>
using namespace std;;
int main() {
    int x = 10;
    double y = 5.5;
    string c = "hehehe";

    cout << "Type of x: " << typeid(x).name() << endl;
    cout << "Type of y: " << typeid(y).name() << endl;
    cout << "Type of c: " << typeid(c).name() << endl;

    return 0;
}
*/

#include<iostream>
using namespace std;
/*
int main(){
	string str = "12345";
	int num = stoi(str);
	
	cout<<"String to Int : "<<num<<endl;
	
	int newNum = 23456;
	int newStr = to_string(newNum);
	
	cout<<"Int to String : "<<endl;
	
	return 0;
}
*/

#include<iostream>
using namespace std;
class A{
	public:
	A(){
		cout<<"A"<<endl;		
	}
};
class B{
	public:
	B(){
		cout<<"B"<<endl;		
	}
};
class C{
	public:
	C(){
		cout<<"C"<<endl;		
	}
};
class D: public B,public C{
	public:
	D(){
		cout<<"D"<<endl;		
	}
};
class E: public A,public C{
	public:
	E(){
		cout<<"E"<<endl;		
	}
};
class F:public B{
	public:
	F(){
		cout<<"F"<<endl;		
	}
};
class G:public F,public E,public D{
	public:
	G(){
		cout<<"G"<<endl;		
	}
};
class H{
	public:
	H(){
		cout<<"H"<<endl;		
	}
};
class I:public H,public D{
	public:
	I(){
		cout<<"I"<<endl;		
	}
};
class J:public G,public H{
	public:
	J(){
		cout<<"J"<<endl;		
	}
};
class K{
	public:
	K(){
		cout<<"K"<<endl;		
	}
};
class L:public K,public J,public I{
	public:
	L(){
		cout<<"L"<<endl;		
	}
};
int main(){
	L l;
	return 0;
}
