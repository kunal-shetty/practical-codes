#include<iostream>
using namespace std;
class objCounter {
	public:
		static int count;
		objCounter(){
			count++;
		}
		~objCounter(){
			count--;
		}
		static void showCount(){
			cout<<"Number of objects created : "<<count<<endl;
		}
};
int objCounter::count = 0;
int main(){
	objCounter::showCount();
	objCounter obj1;
	objCounter::showCount();	
	{
	objCounter obj2,obj3;
	objCounter::showCount();	
	}
	objCounter::showCount();
	return 0;
}
