#include<iostream>
using namespace std;
int main() {
    int arr[] = {2, 4, 1, 5, 3, 7, 9};
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < len; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int sortedArray[len];  
    int index = 0;
    sortedArray[index++] = arr[0]; 
    for(int i = 1; i < len; i++) {
        if(arr[i] >= sortedArray[index - 1]) {
            sortedArray[index++] = arr[i];
        }
    }
    for(int i = 0; i < index; i++)
        cout<<sortedArray[i]<<" ";
    return 0;
}
