#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void insertMaxHeap(int arr[], int &n, int element) {
    n++;
    int i = n - 1;

    arr[i] = element;

    // Bubble up
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
 
int main() {
    int arr[100];
    int n = 0;
    int num_elements;

    cout << "Enter the number of elements to insert into the max heap: ";
    cin >> num_elements;

    cout << "Enter " << num_elements << " elements:\n";
    for (int i = 0; i < num_elements; i++) {
        int element;
        cin >> element;
        insertMaxHeap(arr, n, element);
    }

    cout << "Max Heap after insertions: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}