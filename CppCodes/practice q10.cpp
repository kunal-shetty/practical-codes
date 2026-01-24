#include<iostream>
using namespace std;
class Distance{
	private:
	int meters, centimeters;
	public:
	Distance(int m, int cm) : meters(m), centimeters(cm) {
		convert();
	}
	void convert(){
		while(1){
			if(centimeters < 100) break;
			meters ++;
			centimeters -= 100;
		}
	}
	Distance operator +(const Distance &d){
		Distance sum(0,0);
		sum.meters = meters + d.meters;
		sum.centimeters = centimeters + d.centimeters;
		sum.convert();
		return sum;
	}
	void display() const {
		cout<<meters<<" Meters "<<centimeters<<" Centimeters"<<endl;
	}
};
int main(){
	Distance d1(5,90), d2(9,10);
	Distance d3 = d1 + d2;
	cout<<"Distance after addition : ";
	d3.display();
	return 0;
}