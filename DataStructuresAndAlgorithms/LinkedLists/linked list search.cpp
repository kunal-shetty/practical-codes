//b. wap to search an element in linked list and display its position
#include<iostream>
using namespace std;
//nodes definition
struct Node{
	int value;
	Node *nextptr;
};
//create a linked list
Node* createNode(int value){
	Node* newNode = new Node();
	newNode->value = value;
	newNode->nextptr = NULL;
	return newNode;
}
//insert elements
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
//search elements
void searchList(Node* head, int val){
	Node* temp = head;
	int pos = 1;
	bool found = false;	
	while(temp != NULL){
		if(temp->value == val){
			cout<<"Element found at position "<<pos<<endl;
			found = true;
			return;
		}
		pos++;
		temp = temp->nextptr;
	}
	if(!found) cout<<"Element not found!"<<endl;
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
	cout<<"Enter value to search : ";
	cin>>value;
	searchList(head, value);
	return 0;
}
