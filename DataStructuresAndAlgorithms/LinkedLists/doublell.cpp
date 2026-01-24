#include <iostream>
using namespace std;
// Define a node for the doubly linked list
struct Node {
 int data;
 Node* prev;
 Node* next;
};
// Func to create a new node
Node* createNode(int value) {
 Node* newNode = new Node();
 newNode->data = value;
 newNode->prev = NULL;
 newNode->next = NULL;
 return newNode;
}
// Func to insert node at the end
void insertEnd(Node*& head, int value) {
 Node* newNode = createNode(value);
 if (head == NULL) {
 head = newNode;
 } else {
 Node* temp = head;
 while (temp->next != NULL)
 temp = temp->next;
 temp->next = newNode;
 newNode->prev = temp;
 }
}
// Func to display the list
void displayList(Node* head) {
 if (head == NULL) {
 cout << "List is empty.\n";
 return;
 }
 cout << "Doubly Linked List: ";
 Node* temp = head;
 while (temp != NULL) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
}
// Func to sort the doubly linked list using Bubble Sort
void sortList(Node* head) {
 if (head == NULL) return;
 bool swapped;
 Node* ptr;
 Node* last = NULL;
 do {
 swapped = false;
 ptr = head;
 while (ptr->next != last) {
 if (ptr->data > ptr->next->data) {
 // Swap data
 int temp = ptr->data;
 ptr->data = ptr->next->data;
 ptr->next->data = temp;
 swapped = true;
 }
 ptr = ptr->next;
 }
 last = ptr;
 } while (swapped);
}
int main() {
 Node* head = NULL;
 int n, value, i;
 cout << "Enter the number of nodes: ";
 cin >> n;
 for (i = 0; i < n; i++) {
 cout << "Enter value for node " << i + 1 << ": ";
 cin >> value;
 insertEnd(head, value);
 }
 cout << "\nOriginal List:\n";
 displayList(head);
 sortList(head);
 cout << "\nSorted List:\n";
 displayList(head);
 return 0;
}