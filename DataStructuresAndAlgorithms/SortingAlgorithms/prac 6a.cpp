//wap to implement merge sort 6a
#include<iostream>
using namespace std;
void merge(int arr[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], M[n2];
	
	for(int i = 0; i < n1; i ++)
		L[i] = arr[p + i];
	for(int j = 0; j < n2; j ++)
		M[j] = arr[q + j + 1];
	
	int i = 0, j = 0, k = p;
	while(i < n1 && j < n2){
		if(L[i] <= M[j]){
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++; k++;
	}
	while(j < n2){
		arr[k] = M[j];
		j++; k++;
	}
}
void mergeSort(int arr[], int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		
		merge(arr, l, m, r);
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
	mergeSort(arr, 0, n - 1);
	printArray(arr, n);
	return 0;
}