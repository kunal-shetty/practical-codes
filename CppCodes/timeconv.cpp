#include<iostream>
using namespace std;
int main(){
	int sec,hours,mins;
	cout<<"Enter seconds to be converted into Hours and Minutes"<<endl;
	cin>>sec;
	cout<<sec<<" seconds in hours, minutes and seconds is "<<endl;
	hours = sec/3600;
	sec %= 3600;
	mins = sec/60;
	sec %= 60;
	cout<<hours<<" Hours "<<mins<<" Minutes "<<sec<<" Seconds";
	return 'S';
}
