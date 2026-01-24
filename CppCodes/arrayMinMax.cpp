#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter number of elements in array : ";
	cin>>num;
	int A[num];  
	cout<<"Enter elements for the array\n";
	for(int i = 0; i < num; i++){
		cout<<"Element "<<(i+1)<<" : ";
		cin>>A[i];
	}
	//Finding largest and smallest
	int large = A[0];
	int small = A[0];
	for(int i = 0; i < num; i++){
		if(A[i] > large)
		large = A[i];
		if(A[i] < small)
		small = A[i];
	}
	cout<<"Largest element : "<<large;
	cout<<"\nSmallest element : "<<small;
	return 0;
}