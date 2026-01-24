//wap to create a tree and display the elements
#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node* firstChild;
	struct Node* nextSibling;
};
struct Node* createNode(int value){
	struct Node* newNode = new Node;
	newNode->data = value;
	newNode->firstChild = NULL;
	newNode->nextSibling = NULL;
	return newNode;
}
void addChild(Node *parent, int value){
	Node *child = createNode(value);
	if(parent->firstChild == nullptr)
		parent->firstChild = child ;
	else {
		Node *temp = parent->firstChild;
		while(temp->nextSibling != nullptr)
			temp = temp->nextSibling;
		temp->nextSibling = child;
	}
}
void preorder(Node *root){
	if(root == nullptr) return;
	cout<<root->data<<" ";
	Node *child = root->firstChild;
	while(child != nullptr){
		preorder(child);
		child = child->nextSibling;
	}
}
int main(){
	Node *root = createNode(1);
	addChild(root, 2);
	addChild(root, 3);
	addChild(root, 4);
	addChild(root->firstChild, 5);
	addChild(root->firstChild, 6);
	addChild(root->firstChild->nextSibling, 7);
	cout<<"Tree elements : ";
	preorder(root);
	return 0;
}