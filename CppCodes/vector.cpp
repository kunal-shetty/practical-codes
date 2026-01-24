#include<iostream>
#include<vector>
using namespace std;
int main(){
	int size, n;
	vector<int> num;
	cout<<"How many numbers would u like to insert : ";
	cin>>size;
	for(int i = 0; i < size; i++){
		cout<<"Enter Element "<<(i + 1)<<" : ";
		cin>>n;
		num.push_back(n); 
	}
	for(int i = 0; i < num.size(); i++){
		cout<<num.at(i)<<" "; 
	}
	return 0;
}