#include<iostream>
using namespace std;
int main(){
	int nums, ch;
	cout<<"Enter number of elements : ";
	cin>>nums;
	int arr[nums];
	cout<<"Enter elements for the array\n";
	for(int i = 0; i < nums; i++){
		cout<<"Element "<<(i + 1)<<" : ";
		cin>>arr[i];
	}
	
	for (int i = 0; i < nums; i++) {
		int minIndex = i;
		for(int j = i + 1; j < nums; j++){
			if(arr[minIndex] > arr[j])
			minIndex = j;
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	
	for(int i = 0; i < nums; i++)
	cout<<arr[i]<<" ";
	return 0;
}