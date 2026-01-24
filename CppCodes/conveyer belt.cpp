#include<iostream>
using namespace std;
int main(){
	int arr[8] = {4,5,0,1,9,0,5,0};
	for(int i = 0; i < 8; i++)
		cout<<arr[i]<<" ";
	if(arr[7] != 0)
	for(int i = 0; i < 8; i++){
		if(arr[i] == 0){
			int temp = arr[i];
			arr[i] = arr[7];
			arr[7] = temp;
			break;
		}
	}
	int i =0;
	while(i < 7){
		while(arr[i] == 0){
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			i++;
		}
	}
	cout<<endl;
	for(int i = 0; i < 8; i++)
		cout<<arr[i]<<" ";
	return 0;
}