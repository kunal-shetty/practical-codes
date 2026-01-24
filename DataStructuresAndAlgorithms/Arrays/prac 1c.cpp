//Matrix addition, multiplication, transpose (menu driven)
#include<iostream>
using namespace std;
const int MAX = 5;
void createMatrix(int m[MAX][MAX], int row, int col);
void addMatrix(int m1[MAX][MAX], int row1, int col1, int m2[MAX][MAX], int row2, int col2);
void multMatrix(int m1[MAX][MAX], int row1, int col1, int m2[MAX][MAX], int row2, int col2);
void transpose(int m[MAX][MAX], int row, int col);
void display(int m[MAX][MAX], int row, int col);

int main(){
	int rows1, rows2, cols1, cols2, choice;
	cout<<"Enter rows and columns for 1st Matrix\nRows : ";
	cin>>rows1;
	cout<<"Columns : ";
	cin>>cols1;
	cout<<"Enter rows and columns for 2nd Matrix\nRows : ";
	cin>>rows2;
	cout<<"Columns : ";
	cin>>cols2;
	int a[MAX][MAX], b[MAX][MAX];
	cout<<"Enter elements for 1st matrix\n";
	createMatrix(a, rows1, cols1);
	cout<<"Enter elements for 2nd matrix\n";
	createMatrix(b, rows2, cols2);

	do{
		cout<<"\n1. Add Matrices\n2. Multiply Matrices\n3. Transpose Matrices\n4. Exit\nChoice : ";
		cin>>choice;
		switch(choice){
			case 1: addMatrix(a, rows1, cols1, b, rows2, cols2); break;
			case 2: multMatrix(a, rows1, cols1, b, rows2, cols2); break;
			case 3:
				cout<<"Transpose of 1st Matrix\n";
				transpose(a, rows1, cols1);
				cout<<"Transpose of 2nd Matrix\n";
				transpose(b, rows2, cols2);
				break;
		}
	}while(choice != 4);
	return 0;
}

void createMatrix(int m[MAX][MAX], int row, int col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout<<"Value ("<<i + 1<<", "<<j + 1<<") : ";
			cin>>m[i][j];
		}
	}
	cout<<"Matrix\n";
	display(m, row, col);
}

void addMatrix(int m1[MAX][MAX], int row1, int col1, int m2[MAX][MAX], int row2, int col2){
	if(row1 != row2 || col1 != col2){
		cout<<"Cannot add matrices with different dimensions!\n";
		return;
	}
	cout<<"Sum of matrices\n";
	for(int i = 0; i < row1; i++){
		for(int j = 0; j < col1; j++)
			cout<<m1[i][j] + m2[i][j]<<" ";
		cout<<endl;
	}
}

void multMatrix(int m1[MAX][MAX], int row1, int col1, int m2[MAX][MAX], int row2, int col2){
	if(col1 != row2){
		cout<<"Cannot multiply these matrices!\n";
		return;
	}
	int res[MAX][MAX] = {0};
	for(int i = 0; i < row1; i++){
		for(int j = 0; j < col2; j++){
			for(int k = 0; k < col1; k++)
				res[i][j] += m1[i][k] * m2[k][j];
		}
	}
	cout<<"Product of matrices\n";
	display(res, row1, col2);
}

void transpose(int m[MAX][MAX], int row, int col){
	for(int i = 0; i < col; i++){
		for(int j = 0; j < row; j++)
			cout<<m[j][i]<<" ";
		cout<<endl;
	}
}

void display(int m[MAX][MAX], int row, int col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++)
			cout<<m[i][j]<<" ";
		cout<<endl;
	}
}
