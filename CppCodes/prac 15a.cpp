#include<iostream>
using namespace std;
template <typename T>
class Calculator{
	public:
		T add(T a, T b){
			return a+b;
		}
		T subtract(T a, T b){
			return a-b;
		}
		T multiply(T a, T b){
			return a*b;
		}
		T divide(T a, T b){
			if(b!=0)
			return a/b;
			else{
				cout<<"Error division by zero";
				return 0;
			} 
		}
};
int main(){
	Calculator<int>calcInt;
	int a=10,b=5;
	cout<<"Integer Operations : "<<endl;
	cout<<"Addition : "<<calcInt.add(a,b)<<endl;
	cout<<"Subtraction : "<<calcInt.subtract(a,b)<<endl;
	cout<<"Multiplication : "<<calcInt.multiply(a,b)<<endl;
	cout<<"Division : "<<calcInt.divide(a,b)<<endl;
	
	Calculator<float>calcFloat;
	float x=7.2,y=5.4;
	cout<<"\nFloating Point Operations : "<<endl;
	cout<<"Addition : "<<calcFloat.add(a,b)<<endl;
	cout<<"Subtraction : "<<calcFloat.subtract(a,b)<<endl;
	cout<<"Multiplication : "<<calcFloat.multiply(a,b)<<endl;
	cout<<"Division : "<<calcFloat.divide(a,b)<<endl;
	
	return 0;
}