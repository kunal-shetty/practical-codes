//wap to implement queue with insert, delete, display and exit
#include<iostream>
#define MAX 10
using namespace std;

void enqueue(int value);
void dequeue();
void display();

int queue[MAX];
int front = -1;
int rear = -1;

int main() {
	int ch, val;
	while(true) {
		cout<<"\nQueue Operations\n";
		cout<<"1. Insert (Enqueue)\n";
		cout<<"2. Delete (Dequeue)\n";
		cout<<"3. Display\n";
		cout<<"4. Exit\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch) {
			case 1:
			cout<<"Enter the element to insert : ";
			cin>>val;
			enqueue(val);
			break;
			case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
			case 4:
			cout<<"Exiting the program....";
			return 0;
			default:
			cout<<"Invalid choice! Please try again.\n";
		}
	}
}

void enqueue(int value) {
	if(rear == MAX - 1)
	cout<<"Queue is full, Cannot insert item!\n";
	else {
		rear++;
		queue[rear] = value;
		cout<<"Element "<<value<<" has been inserted successfully\n";
	}
}

void dequeue() {
	if(front == -1 && rear == -1)
	cout<<"Queue is empty, cannot delete elements!";
	else {
		int deletedVal = queue[front];
		if(front == rear) {
			front = -1;
			rear = -1;
		}
		else front++;
		cout<<"Element "<<deletedVal<<" has been deleted!\n";
	}
}

void display() {
	if(front == -1 && rear == -1)
	cout<<"Queue is empty, nothing to display!\n";
	else {
		cout<<"Elements in the queue : ";;
		for(int i = front + 1; i <= rear; i++)
		cout<<queue[i]<<" ";
		cout<<endl;
	}
}