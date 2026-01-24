//wap to implement insertion sort 5c
#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
	for(int i = 0; i < n; i ++){
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n){
	cout<<"Sorted Array\n";
	for(int i = 0; i < n; i ++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
	int arr[5] = {64, 25, 12, 22, 11};
//	int n = sizeof(arr) / sizeof(arr[0]);
	int n = 5;
	insertionSort(arr, n);
	printArray(arr, n);
	return 0;
}