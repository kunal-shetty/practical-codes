#include<iostream>
using namespace std;
int mySqrt(int x) {
	if(x <= 0)
	return x;
	for(float i = 0; i < x; i += 0.1){
		float check = i * i;
		if((int)check == x)
		return (int)i;
	}
	return -1;
}