//prac 2 - implement the followinig for linked lists
//a. wap to create a single linked list and display the node elements in reverse
#include<iostream>
using namespace std;
struct Node {
	int value;
	Node* nextptr;
};
Node *createNode(int value){
	Node *newNode = new Node();
	newNode->value = value;
	newNode->nextptr = NULL;
	return newNode;
}
void insertEnd(int value, Node* &head){
	Node *newNode = createNode(value);
	if(head == NULL) head = newNode;
	else{
		Node *temp = head;
		while(temp->nextptr != NULL)
			temp= temp->nextptr;
		temp->nextptr = newNode;
	}
}

void display(Node *head){
	Node *temp = head;
	while(temp != NULL){
		cout<<temp->value<<" ";
		temp = temp->nextptr;
	}
}
void reverseDisplay(Node *head){
	Node *temp = head;
	if(temp == NULL) return;
	reverseDisplay(temp->nextptr);
	cout<<temp->value<<" ";
}
int searchList(int val, Node *head){
	Node *temp = head;
	int count = 0;
	while(temp != NULL){
		if(temp->value == val) return count + 1;
		count++; 
		temp = temp->nextptr;
	}
	return 0;
}
int main(){
	Node *head = NULL;
	int n, value;
	cout<<"Enter number of nodes : ";
	cin>>n;
	for(int i = 0; i < n; i++){
		cout<<"Enter value for Node "<<(i + 1)<<" : ";
		cin>>value;
		insertEnd(value, head);
	}
	display(head);
	cout<<endl;
	reverseDisplay(head);
	cout<<endl<<"Enter value to search : ";
	cin>>value;
	if(searchList(value, head))
		cout<<"Value found at position "<<searchList(value, head)<<"!";
	else 
		cout<<"Not found";
		
	return 0;
}
