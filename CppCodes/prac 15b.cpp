#include<iostream>
using namespace std;
template<typename T>
T getMax(T a, T b){
	return (a > b) ? a : b;
}
int main(){
	int num1 = 10, num2 = 20;
	cout<<"Maximum of "<<num1<<" and "<<num2<<" is "<<getMax(num1, num2)<<endl;
	float float1 = 12.5f, float2 = 7.2f;
	cout<<"Maximum of "<<float1<<" and "<<float2<<" is "<<getMax(float1, float2)<<endl;
	char char1 = 'A', char2 = 'B';
	cout<<"Maximum of "<<char1<<" and "<<char2<<" is "<<getMax(char1, char2)<<endl;
	return 0;
}