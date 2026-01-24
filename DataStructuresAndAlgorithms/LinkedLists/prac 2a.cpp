#include <iostream>
using namespace std;
// Define a node structure
struct Node {
    int data;
    Node* next;
};
// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();  // Dynamically allocate memory for new node
    newNode->data = value;       // Assign value to the data field
    newNode->next = NULL;        // Initialize next to NULL
    return newNode;              // Return pointer to the new node
}

// Function to insert a node at the end
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);  // Create a new node with the given value

    if(head == NULL) {                 // If list is empty
        head = newNode;                 // New node becomes the head
    } else {
        Node* temp = head;             // Temporary pointer to traverse list
        while(temp->next != NULL)     // Traverse until the last node
            temp = temp->next;
        temp->next = newNode;          // Link last node to new node
    }
}
// Function to display list in reverse using recursion
void displayReverse(Node* head) {
    if(head == NULL)
        return;                        // Base case: end of list
    displayReverse(head->next);       // Recursive call to next node
    cout<<head->data<<" ";        // Print during unwinding (reverse order)
}

int main() {
    Node* head = NULL;                // Initialize head pointer to NULL
    int n, value;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        cout<<"Enter value for node " << i + 1 << ": ";
        cin>>value;
        insertEnd(head, value);       // Insert value at the end
    }
    cout<<"Linked list in reverse order: ";
    displayReverse(head);             // Display the list in reverse
    cout<<endl;
    return 0;
}


