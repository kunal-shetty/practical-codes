#include<iostream>
using namespace std;
void createArray(int a[], int size){
	for(int i = 0; i < size; i++){
		cout<<"Element "<<(i + 1)<<" : ";
		cin>>a[i];
	}
}
int main(){
	int len1, len2;
	cout<<"Enter size for 1st array : ";
	cin>>len1;
	int arr1[len1];
	cout<<"Enter elements for array : \n";
	createArray(arr1, len1);
	cout<<"Enter size for 2nd array : ";
	cin>>len2;
	int arr2[len2];
	cout<<"Enter elements for array : \n";
	createArray(arr2, len2);
	int mergedArray[len1 + len2];
	int index = 0;
	int ptr1 = 0;
	int ptr2 = 0;
	while(len1 > ptr1){
		mergedArray[index++] = arr1[ptr1];
		ptr1++;
	}
	while(len2 > ptr2){
		mergedArray[index++] = arr2[ptr2];
		ptr2++;
	}
	for(int i = 0; i < index; i++){
		for(int j = 0; j < len1 + len2 - i - 1; j++){
			if(mergedArray[j] > mergedArray[j + 1]){
				int temp = mergedArray[j];
				mergedArray[j] = mergedArray[j + 1];
				mergedArray[j + 1] = temp;
			}
		}
	}
	cout<<"Merged and sorted array : "<<endl;
	for(int i = 0; i < len1 + len2; i++)
		cout<<mergedArray[i]<<" ";
	return 0;
}