#include<iostream>
using namespace std;
int main(){
	int arr[] = {2,3,9,6,3,6,2,3,5,4,2,3,4,3};
	int size = sizeof(arr) / sizeof(arr[0]);
	int popCount = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] == 3){
			popCount++;
			for(int j = i; j < size; j++)
			arr[j] = arr[j+1];
		}
	}
	for(int i = 0; i < size - popCount; i++)
	cout<<arr[i]<<" ";
	return 0;
}