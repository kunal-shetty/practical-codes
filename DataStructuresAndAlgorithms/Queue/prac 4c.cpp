#include <iostream>
using namespace std;

const int MAX = 5;
int q[MAX];
int front = -1, rear = -1;

bool isFull() {
    return (front == (rear + 1) % MAX);
}

bool isEmpty() {
    return (front == -1);
}

void insertRear() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    if (isFull()) {
        cout << "Queue is full.\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    q[rear] = val;
    cout << "Inserted at rear.\n";
}

void insertFront() {
    int val;
    cout << "Enter value: ";
    cin >> val;
    if (isFull()) {
        cout << "Queue is full.\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    q[front] = val;
    cout << "Inserted at front.\n";
}

void deleteFront() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Deleted from front: " << q[front] << "\n";
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void deleteRear() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Deleted from rear: " << q[rear] << "\n";
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n*** Main Menu ***\n"
             << "1. Insert Rear\n"
             << "2. Insert Front\n"
             << "3. Delete Front\n"
             << "4. Delete Rear\n"
             << "5. Display\n"
             << "6. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertRear(); break;
            case 2: insertFront(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}