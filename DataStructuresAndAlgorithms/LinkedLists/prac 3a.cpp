#include <iostream>
#define MAX 5
using namespace std;
int stack[MAX];
int top = -1;
void push();
void pop(); 
void display();
int main() {
 int choice;
 while (true) {
 cout << "\nStack Operations Menu:\n";
 cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1: push(); break;
 case 2: pop(); break;
 case 3: display(); break;
 case 4: cout << "Exiting program...\n"; return 0;
 default: cout << "Invalid choice! Please try again.\n";
 }
 }
 return 0;
}
// Push func
void push() {
 if (top == MAX - 1) {
 cout << "Stack is full! (Overflow)\n";
 } else {
 int val;
 cout << "Enter element to push: ";
 cin >> val;
 top++;
 stack[top] = val;
 cout << val << " pushed onto the stack.\n";
 }
}
// Pop func
void pop() {
 if (top == -1) {
 cout << "Stack is empty! (Underflow)\n";
 } else {
 cout << "Popped element: " << stack[top] << endl;
 top--;
 }
}
// Display func
void display() {
 if (top == -1) {
 cout << "Stack is empty!\n";
 } else {
 cout << "Stack elements (top to bottom):\n";
 for (int i = top; i >= 0; i--) {
 cout << stack[i] << endl;
 }
 }
}