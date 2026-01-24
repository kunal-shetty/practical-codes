#include <iostream>
using namespace std;
// Define a node structure
struct Node {
    int data;
    Node* next;
};
// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if(head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to display the list
void displayList(Node* head) {
    if(head == NULL) {
        cout<<"List is empty.\n";
        return;
    }

    cout<<"Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Function to search for a value in the list
void searchList(Node* head, int key) {
    Node* temp = head;
    int pos = 1;
    bool found = false;
    while(temp != NULL) {
        if(temp->data == key) {
            cout<<"Element "<<key<<" found at position "<<pos<<".\n";
            found = true;
        }
        temp = temp->next;
        pos++;
    }
    if(!found)
        cout<<"Element "<<key<<" not found in the list.\n";
}
int main() {
    Node* head = NULL;
    int n, value, key, i;

    cout<<"Enter the number of nodes: ";
    cin>>n;
    for(i = 0; i < n; i++) {
        cout<<"Enter value for node "<<i + 1<<": ";
        cin>>value;
        insertEnd(head, value);
    }
    displayList(head);
    cout<<"Enter value to search in the list: ";
    cin>>key;
    searchList(head, key);
    return 0;''
}

