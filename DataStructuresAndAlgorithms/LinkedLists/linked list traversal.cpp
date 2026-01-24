//prac 2 - implement the followinig for linked lists
//a. wap to create a single linked list and display the node elements in reverse
#include<iostream>
using namespace std;
//nodes definition
struct Node{
	int value;
	Node *nextptr;
};
//create a node
Node* createNode(int value){
	Node* newNode = new Node();
	newNode->value = value;
	newNode->nextptr = NULL;
	return newNode;
}
//insert node elements
void insertEnd(Node* &head, int value){
	Node* newNode = createNode(value);
	if(head == NULL) head = newNode;
	else{
		Node* temp = head;
		while(temp->nextptr != NULL)
			temp = temp->nextptr;
		temp->nextptr = newNode;
	}
}
//traversal
void displayList(Node* head){
	if(head == NULL){
		cout<<"List is empty";
		return;
	}
	cout<<"Linked list : ";
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->value<<" ";
		temp = temp->nextptr;
	}
}

void displayReverse(Node* head){
	if(head == NULL){
		return;
	}
	displayReverse(head->nextptr);
	cout<<head->value<<" ";
}

int main(){
	Node* head = NULL;
	int n, value;
	cout<<"Enter number of nodes : ";
	cin>>n;
	for(int i = 0; i < n; i++){
		cout<<"Enter value for node "<<i + 1<<" : ";
		cin>>value;
		insertEnd(head, value);
	}
	displayList(head);
	cout<<endl<<"Linked list in reverse order : ";
	displayReverse(head);
}


