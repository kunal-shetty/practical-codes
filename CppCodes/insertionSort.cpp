#include<iostream>
using namespace std;
int main() {
    int nums;
    cout << "Enter number of elements: ";
    cin >> nums;
    int arr[nums];
    cout << "Enter elements for the array:\n";
    for (int i = 0; i < nums; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    for (int i = 1; i < nums; i++) {
        int key = arr[i];          
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];    
            j--;
        }
        arr[j + 1] = key;          
    }
    cout << "\nSorted array using Insertion Sort:\n";
    for (int i = 0; i < nums; i++)
        cout << arr[i] << " ";

    return 0;
}
