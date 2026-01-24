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
void preorder(Node *root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node *root){
	if(root == NULL) return;
	postorder(root->left);
	cout<<root->data<<" ";
	postorder(root->right);
}
int main(){
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	cout<<"Inorder traversal : ";
	inorder(root);
	cout<<"\nPreorder traversal : ";
	preorder(root);
	cout<<"\nPostorder traversal : ";
	postorder(root);
	return 0;
}