#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	string str = "Hello";
	cout<<setw(20)<<setfill('*')<<str<<endl;
	cout.width(15);
	cout.fill('#');
	cout<<str<<endl;
	
	cout.setf(ios::showpos);
	cout<<123<<endl;
	cout.unsetf(ios::showpos);
	cout<<123<<endl;

	double number = 3.14159265358979;
	cout<<"Original Number : "<<number<<endl;
	cout<<"With precision 4 : "<<setprecision(4)<<number<<endl;
	cout<<"With precision 6 : "<<setprecision(6)<<number<<endl;
	
	int n1 = 100, n2 = 1234;
	cout<<"n1 in decimal : "<<dec<<n1<<endl;
	cout<<"n1 in hexadecimal : "<<hex<<n1<<endl;
	cout<<"n1 in octal : "<<oct<<n1<<endl;
	cout<<"n2 in decimal : "<<dec<<n2<<endl;
	
	double pi = 3.14159;
	cout.setf(ios::fixed);
	cout<<"PI in fixed format : "<<pi<<endl;
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout<<"PI in scientific form : "<<pi<<endl;
	cout.unsetf(ios::scientific);
	cout.setf(ios::showpoint);
	cout<<"PI with showpoint : "<<pi<<endl;
	cout.unsetf(ios::showpoint);
	cout<<"PI with default format : "<<pi<<endl;
	
	bool flag = true;
	cout<<"Flag as bool(true) : "<<boolalpha<<flag<<endl;
	cout<<"Flag as int(1) : "<<noboolalpha<<flag<<endl;
	
	int numberAligned = 45;
	cout.setf(ios::left);
	cout<<"Left aligned : "<<setw(10)<<numberAligned<<endl; 
	cout.setf(ios::right);
	cout<<"Right aligned : "<<setw(10)<<numberAligned<<endl;
	cout.setf(ios::internal);
	cout<<"Internal aligned : "<<setw(10)<<numberAligned<<endl;
	
	int posnum = 42; 
	int negnum = -42;
	cout.setf(ios::showpos);
	cout<<"Positive number with sign : "<<posnum<<endl;
	cout<<"Negative number with sign : "<<negnum<<endl;
                                                
	return 0;

}
