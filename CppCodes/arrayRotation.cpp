#include<iostream>
using namespace std;
void rotateLeft(int arr[], int size){
	int temp = arr[0];
	for(int i = 0; i < size; i++){
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = temp;
}
void rotateRight(int arr[], int size){
	int temp = arr[size - 1];
	for(int i = size - 1 ; i > 0; i--){
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
}
int main(){
	int num, ch, times;
	cout<<"Enter number of elements : ";
	cin>>num;
	int arr[num];
	cout<<"Enter elements for the array\n";
	for(int i = 0; i < num; i++){
		cout<<"Element "<<(i + 1)<<" : ";
		cin>>arr[i];
	}
	while(ch != 4){
		cout<<"What operation would you like to perform : \n1. Left Rotation\n2. Right Rotation\n3. Display Array\n4. Exit\nInput : ";
		cin>>ch;
		if(ch == 1){
			cout<<"How many times? : ";
			cin>>times;
			while(times != 0){
				rotateLeft(arr, num);
				times--;
			}
			for(int i = 0; i < num; i++)
			cout<<arr[i]<<" ";
		}
		if(ch == 2){
			cout<<"How many times? : ";
			cin>>times;
			while(times != 0){
				rotateRight(arr, num);
				times--;
			}
			for(int i = 0; i < num; i++)
			cout<<arr[i]<<" ";
		}
		if(ch == 3){
			for(int i = 0; i < num; i++)
			cout<<arr[i]<<" ";
		}
		if(ch == 4){
			cout<<"Exiting the program!!";
			return 0;
		}
		cout<<endl;
	}
	return 0;
}