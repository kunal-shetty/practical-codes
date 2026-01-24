//Matrix addition, matrix multiplication, matrix transpose (menu driven)
#include<iostream>
using namespace std;
//global vars 
const int MAX = 5;
//global funcs
void createMatrix(int m[MAX][MAX], int row, int col);
void addMatrix(int m1[MAX][MAX], int row1, int col1, int m2[MAX][MAX], int row2, int col2);
void multMatrix(int m1[MAX][MAX], int row1, int col1, int m2[MAX][MAX], int row2, int col2);
void transpose(int m[MAX][MAX], int row, int col);
void display(int m[MAX][MAX], int row, int col);
//main
int main(){
	int rows1, rows2, cols1, cols2, sum = 0;
	cout<<"Enter number of rows and columns for 1st Matrix\nRows : ";
	cin>>rows1;
	cout<<"Columns : ";
	cin>>cols1;
	cout<<"Enter number of rows and columns for 2nd Matrix\nRows : ";
	cin>>rows2;
	cout<<"Columns : ";
	cin>>cols2;
	int a[rows1][cols1];
	int b[rows2][cols2];
	cout<<"Enter elements for 1st matrix\n";
	for(int i = 0; i < rows1; i++){
		for(int j = 0; j < cols1; j++){
			cout<<"Value ("<<i + 1<<", "<<j + 1<<") : ";
			cin>>a[i][j];
		}
	}
	cout<<"1st Matrix\n";
	for(int i = 0; i < rows1; i++){
		for(int j = 0; j < cols1; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Enter elements for 2nd matrix\n";
	for(int i = 0; i < rows2; i++){
		for(int j = 0; j < cols2; j++){
			cout<<"Value ("<<i + 1<<", "<<j + 1<<") : ";
			cin>>b[i][j];
		}
	}
	cout<<"2nd Matrix\n";
	for(int i = 0; i < rows2; i++){
		for(int j = 0; j < cols2; j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	if(rows1 != rows2 || cols1 != cols2){
		cout<<"Cannot add matrix with different dimensions!";
		return 1;
	}
	else{
		cout<<"Sum of the matrices\n";
		for(int i = 0; i < rows1; i++){
			for(int j = 0; j < cols1; j++)
				cout<<(a[i][j] + b[i][j])<<" ";
			cout<<endl;
		}
	}
	cout<<"Transpose of 1st Matrix\n";
	for(int i = 0; i < rows1; i++){
		for(int j = 0; j < cols1; j++)
			cout<<a[j][i]<<" ";
		cout<<endl;
	}
	cout<<"Transpose of 2nd Matrix\n";
	for(int i = 0; i < rows2; i++){
		for(int j = 0; j < cols2; j++)
			cout<<b[j][i]<<" ";
		cout<<endl;
	}
	if(rows2 != cols1){
		cout<<"Cannot multiply matrices!!";
		return 1;
	}
	else{
		cout<<"Multiplication of Matrices : \n";
		for(int i = 0; i < rows1; i++){
			for(int j = 0; j < cols1; j++){
				for(int k = 0; k < rows1; k++){
					sum += a[i][k] * b[k][j];
				}
				cout<<sum<<" ";
				sum = 0;
			}
			cout<<endl;
		}
	}
	return 0;
}
void createMatrix(int m[MAX][MAX], int row, int col){
	
}