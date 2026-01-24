#include <iostream>
using namespace std;

#define SIZE 10

void insert(int hashTable[], int key) {
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1) { // find empty slot
        i++;
    }
    hashTable[(index + i) % SIZE] = key;
}

void display(int hashTable[]) {
    cout << "Hash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            cout << i << " --> " << hashTable[i] << endl;
        else
            cout << i << " --> " << "empty" << endl;
    }
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;  // initialize table

    int n;
    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter " << n << " keys:\n";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        insert(hashTable, key);
    }

    display(hashTable);
    return 0;
}