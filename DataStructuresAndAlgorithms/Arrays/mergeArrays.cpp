#include<iostream>
using namespace std;
int main(){
	int arr1[] = {1,3,6};
	int arr2[] = {2,5,9};
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	int finalLength = len1 + len2;
	int mergedArray[finalLength];
	int pointer1 = 0; 
	int pointer2 = 0;
	int iterable = 0;
	while(iterable < finalLength){
		if(arr1[pointer1] < arr2[pointer2]){
			mergedArray[iterable] = arr1[pointer1];
			pointer1++;
		}
		else{
			mergedArray[iterable] = arr2[pointer2];
			pointer2++;
		}
		iterable++;
	}
	for(int i = 0; i < finalLength; i++)
		cout<<mergedArray[i]<<" ";
	return 0;
}