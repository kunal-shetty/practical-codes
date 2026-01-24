#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int randomIndex = rand() % n;
        swap(arr[i], arr[randomIndex]);
    }
}

void bogosort(int arr[], int n) {
    while (!isSorted(arr, n)) {
        shuffle(arr, n);
    }
}

int main() {
    srand(time(0)); 

    int arr[] = {3, 2, 5, 1, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bogosort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

