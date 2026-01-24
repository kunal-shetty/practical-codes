// WAP to store elements in 1D array and perform operations like sorting, searching, reversing.
#include<iostream>
using namespace std;
// Function declarations
void createArray(int a[], int size);
void sort(int a[], int size);
int search(int a[], int size, int val);
void reverse(int a[], int size);
void display(int a[], int size);
int main() {
    int size, ch, val, pos;
    cout<<"Enter number of elements: ";
    cin>>size;
    int a[size];
    do{
    	cout<<"\nMenu\n"
            <<"1. Create Array\n"
            <<"2. Search Element\n"
            <<"3. Reverse Array\n"
            <<"4. Sort Array\n"
            <<"5. Display Array\n"
            <<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch (ch) {
            case 1:
                createArray(a, size);
                cout<<"Array created succesfully!"<<endl;
                break;
            case 2:
                cout<<"Enter element to search: ";
                cin>>val;
                if (pos = search(a, size, val))
                    cout<<"Element found at position " <<pos<<endl;
                else
                    cout<<"Element not found "<<endl;
                break;
            case 3:
                cout<<"Elements in Reverse Order:\n";
                reverse(a, size);
                break;
            case 4:
                cout<<"Sorted Array:\n";
                sort(a, size);
                display(a, size);
                break;
            case 5:
                display(a, size);
                break;
            case 6:
                exit(0);
            default:
                cout<<"Invalid Choice\n";
                break;
        }
    } while (ch != 6);
    return 0;
}
void createArray(int a[], int size) {
    cout<<"Enter elements of the array:\n";
    for(int i = 0; i < size; i++) {
        cout<<"Element "<<i + 1<<": ";
        cin>>a[i];
    }
}
void display(int a[], int size) {
    for(int i = 0; i < size; i++) {
        cout<<a[i]<<" ";
    }
}
int search(int a[], int size, int val) {
    for(int i = 0; i < size; i++) {
        if(a[i] == val)
            return (i + 1);
    }
    return 0;
}
void sort(int a[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void reverse(int a[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        cout<<a[i]<< " ";
    }
    cout<<endl;
}