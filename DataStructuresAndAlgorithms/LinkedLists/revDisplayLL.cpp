#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};

Node *createNode(int value){
	Node *newNode = new Node();
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void insertEnd(Node* &head, int value){
	Node* newNode = createNode(value);
	if(head == NULL) head = newNode;
	else{
		Node* temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
}

void displayList(Node *&head){
	Node *temp = head;
	cout<<"Linked List : ";
	while(temp != NULL){
		cout<<temp->value<<" ";
		temp = temp->next;
	}	
}

void reverseDisplay(Node *&head){
	if(head == NULL){
		cout<<endl<<"Linked list in reverse order : ";
		return;
	}
	reverseDisplay(head->next);
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
	reverseDisplay(head);
}

