#include<iostream>
using namespace std;

void createArray(int a[], int size){
	for(int i = 0; i < size; i++){
		cout<<"Element "<<(i + 1)<<" : ";
		cin>>a[i];
	}
}

void displayArray(int a[], int size){
	for(int i = 0; i < size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void mergeSortArrays(int arr1[], int len1, int arr2[], int len2){
	int mergedArray[len1 + len2], index = 0, ptr1 = 0, ptr2 = 0;
	while(ptr1 < len1) mergedArray[index++] = arr1[ptr1++];
	while(ptr2 < len2) mergedArray[index++] = arr2[ptr2++];
	for(int i = 0; i < index; i++){
		for(int j = 0; j < index - i - 1; j++){
			if(mergedArray[j] > mergedArray[j + 1]){
				int temp = mergedArray[j];
				mergedArray[j] = mergedArray[j + 1];
				mergedArray[j + 1] = temp;
			}
		}
	}
	cout<<"Merged and sorted array : ";
	displayArray(mergedArray, len1 + len2);
}

int main(){
	int len1, len2, choice;
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

	do{
		cout<<"\n1. Display 1st Array\n2. Display 2nd Array\n3. Merge & Sort Arrays\n4. Exit\nChoice : ";
		cin>>choice;
		switch(choice){
			case 1: displayArray(arr1, len1); break;
			case 2: displayArray(arr2, len2); break;
			case 3: mergeSortArrays(arr1, len1, arr2, len2); break;
		}
	}while(choice != 4);

	return 0;
}
