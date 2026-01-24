#include <iostream>
using namespace std;
int main() {
    int a,b;
    char ch;
    cout<<"Enter your operation\n+ for Addition\n- for Subtraction\n* for Multiplication\n/ for Division"<<endl;
    cin>>ch;
    cout<<"Enter numbers"<<endl;
    cin>>a>>b;
    switch(ch) {
    	case '+':
    	cout<<"Sum of the numbers : "<<a+b<<endl;
    	break;
    	case '-':
    	cout<<"Difference of the numbers : "<<a-b<<endl;
    	break;
    	case '*':
    	cout<<"Product of the numbers : "<<a*b<<endl;
    	break;
    	case '/':
    	if(b!=0){
    		cout<<"Quotient of the numbers : "<<a/b<<endl;
    		cout<<"Remainder of the numbers : "<<a%b<<endl;
    	}
    	else
    	cout<<"Error : Division by zero is not possible"<<endl;
    	break;
    	default :
    	cout<<"Invalid Input";
    	break;
	}
    return 0;
}
