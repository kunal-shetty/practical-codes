//wappp to implement selection sort 5b
#include<iostream>
using namespace std;
void selectionSort(int arr[], int n){
	for(int i = 0; i < n - 1; i ++){
		int minIndex = i;
		for(int j = i + 1; j < n; j ++){
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
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
	selectionSort(arr, n);
	printArray(arr, n);
	return 0;
}