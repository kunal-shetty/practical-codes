//Read two arrays from the user, merge them and display them in sorted order (Menu- driven)
//create, merge, sort
#include<iostream>
void mergeArray(int arr1[], int size1, int arr2[], int size2);
void sortArray(int arr[], int size);
int mergedArray[20];
using namespace std;
void createArray(int a[], int size){
	cout<<"Enter elements for array : \n";
	for(int i = 0; i < size; i++){1	
		cout<<"Element "<<(i + 1)<<" : ";
		cin>>a[i];
	}
}
int main(){
	int len1, len2;
	cout<<"Enter size for 1st array : ";
	cin>>len1;
	int arr1[len1];
	cout<<"Enter size for 2nd array : ";
	cin>>len2;
	int arr2[len2];
	int ch;
	do{
		cout<<"Menu\n1. Create two arrays\n2. Merge array\n3.  Display array\n";
		cin>>ch;
		switch(ch){
			case 1:
			createArray(arr1, len1);
			createArray(arr2, len2);
			break;
			case 2:
			mergeArray(arr1, len1, arr2, len2);
			cout<<"Merged array\n";
			for(int i = 0; i < len1 + len2; i++)
				cout<<mergedArray[i]<<" ";
			cout<<"\nWould you also like to sort the array?\n1. Yes\n2. No\nAnswer : ";
			cin>>ch;
			if(ch == 1){
				sortArray(mergedArray, len1 + len2);
				for(int i = 0; i < len1 + len2; i++)
				cout<<mergedArray[i]<<" ";
			else
				break;
			break;
			case 3:
			for(int i = 0; i < len1 + len2; i++)
				cout<<mergedArray[i]<<" ";
			break;
			default:
			cout<<"Invalid Input\n";
		}
		cout<<"\nContinue?\n1. Yes\n2. No\n";
		cin>>ch;
	}while(ch == 1);	
	return 0;
}
void mergeArray(int arr1[], int size1, int arr2[], int size2){
	int index = 0;
	int ptr1 = 0;
	int ptr2 = 0;
	while(size1 > ptr1){
		mergedArray[index++] = arr1[ptr1];
		ptr1++;
	}
	while(size2 > ptr2){
		mergedArray[index++] = arr2[ptr2];
		ptr2++;
	}
}
void sortArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(mergedArray[j] > mergedArray[j + 1]){
				int temp = mergedArray[j];
				mergedArray[j] = mergedArray[j + 1];
				mergedArray[j + 1] = temp;
			}
		}
	}
}