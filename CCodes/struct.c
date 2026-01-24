#include<stdio.h>

struct Book
{
	char title[50];
	char author[50];
	char subject[50];
	int id;
};

void inputdetails(struct Book *b){
	printf("Enter book name\n");
	fgets(b->title,sizeof(b->title),stdin);	
	printf("Enter book author\n");
	fgets(b->author,sizeof(b->author),stdin);	
	printf("Enter book subject\n");
	fgets(b->subject,sizeof(b->subject),stdin);	
	printf("Enter book id\n");
	scanf("%d",&b->id);
	getchar();
}
void printbook(struct Book *b){
	printf("Book name : %s\n",b->title);
	printf("Book author : %s\n",b->author);
	printf("Book subject : %s\n",b->subject);
	printf("Book id : %d\n",b->id);
}

void main(){
	struct Book b1;
	struct Book b2;
	printf("Enter Book 1 Details\n");
	inputdetails(&b1);
	printf("Enter Book 2 Details\n");
	inputdetails(&b2);
	printbook(&b1);
	printbook(&b2);
}
