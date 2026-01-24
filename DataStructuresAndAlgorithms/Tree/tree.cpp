//wap to create a tree and display the elements
#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* createNode(int value){
	struct Node* newNode = new Node;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void display(Node* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	display(root->left);
	display(root->right);
}
int main(){
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	cout<<"Tree elements : \n";
	display(root);
	return 0;
}