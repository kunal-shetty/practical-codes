#include <iostream>
using namespace std;

// Swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert an element into Min Heap
void insertMinHeap(int arr[], int *n, int value) {
    (*n)++;               // increase heap size
    int i = (*n) - 1;     // insert at last position
    arr[i] = value;

    // Fix the min heap property by bubbling up
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int arr[100];   // heap array
    int n = 0;      // current size of heap
    int num;

    cout << "Enter number of elements: ";
    cin >> num;

    cout << "Enter " << num << " elements:\n";
    for (int i = 0; i < num; i++) {
        int x;
        cin >> x;
        insertMinHeap(arr, &n, x);
    }

    cout << "Min Heap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}