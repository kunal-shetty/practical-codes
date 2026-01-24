#include<iostream>
#define PI 3.141592
using namespace std;
float volsq(float side){
	return side*side*side;
}
float volcone(float r,float h){
	return (1.0/3)*PI*r*r*h;
}
float volrect(int l,int b,int h){
	return l*b*h;
}
int main(){
	float s,r,h;
	int l,b,hrect;
	int ch;
	cout<<"Enter your choice\n1. Volume of a Square\n2. Volume of a Cone\n3. Volume of a Rectangle"<<endl;;;;
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"Enter the value for side of the square"<<endl;
			cin>>s;
			cout<<"Volume : "<<volsq(s);
			break;
		case 2:
			cout<<"Enter the values for height and radius of the cone"<<endl;
			cout<<"Height : ";
			cin>>h;
			cout<<"Radius : ";
			cin>>r;
			cout<<"Volume : "<<volcone(r,h);
			break;
		case 3:
			cout<<"Enter values for length, breadth and height for the rectangle";
			cin>>l>>b>>hrect;
			cout<<"Volume : "<<volrect(l,b,hrect);
			break;
		default : 
			cout<<"Invalid Input";
			break;	
	}
	return 0;
}

