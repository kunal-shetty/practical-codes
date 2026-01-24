#include<iostream>
using namespace std;
int main(){
	int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int insertPos = 6, insertVal = 5, deletePos = 2;
	
	//Insert between start
	int temp = insertPos - 1;
	for(int i = 0; i < 12; i++){
		if(arr[i] == 0) break;
		cout<<arr[i]<<" ";
	}
	for(int i = (sizeof(arr) / sizeof(arr[0])) - 1; i >= temp; i--){
		arr[i + 1] = arr[i];
	}
	cout<<endl;
	arr[temp] = insertVal;
	for(int i = 0; i < 12; i++){
		if(arr[i] == 0) break;
		cout<<arr[i]<<" ";
	}
	
	//Insert between end
	
	//Delete between start
	for(int i = deletePos + 1; i < 12; i++){
		arr[i - 1] = arr[i];
	}
	cout<<endl;
	for(int i = 0; i < 12; i++){
		if(arr[i] == 0) break;
		cout<<arr[i]<<" ";
	}
	
	//Delete between end
	
}