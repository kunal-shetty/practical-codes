//4b. wap to implement the concept of circular queue
#include<iostream>
using namespace std;
const int MAX = 5;
int front = -1, rear = -1;
int queue[MAX];
void insertToQueue() {
	int val;
	cout<<"Enter value : ";
	cin>>val;
	if((rear + 1) % MAX == front) 
	cout<<"Queue is full!\n";
	else if(rear == -1) {
		rear = front = 0;
		queue[rear] = val;
		cout<<"Inserted Successfully!\n";
	}
	else {
		rear = (rear + 1) % MAX;
		queue[rear] = val;
		cout<<"Inserted successfully!\n";
	}
}
int deleteFromQueue() {
	if(front == -1) {
		cout<<"Queue is empty!!\n";
		return -1;
	}
	else if(front == rear){
		int val = queue[front];
		front = rear = -1;
		cout<<"Deleted value : "<<val<<endl;
		return val;
	}
	else {
		int val = queue[front];
		front = (front + 1) % MAX;
		cout<<"Deleted value : "<<val<<endl;
		return val;
	}
}
void display() {
	if(front == -1)
	cout<<"Queue is empty!\n";
	else {
		cout<<"Queue : ";
		int i = front;
		while(true) {
			cout<<queue[i]<<" ";
			if(i == rear) break;
			i = (i + 1) % MAX;
		}
		cout<<endl;
	}
}
int main() {
	int ch, val;
	while(true) {
		cout<<"\nCircular Queue Operations\n";
		cout<<"1. Insert\n";
		cout<<"2. Delete\n";
		cout<<"3. Display\n";
		cout<<"4. Exit\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch) {
			case 1: insertToQueue(); break;
			case 2: deleteFromQueue(); break;
			case 3: display(); break;
			case 4: cout<<"Exiting the program...."; return 0;
			default: cout<<"Invalid choice! Please try again.\n";
		}
	}
	return 0;
}