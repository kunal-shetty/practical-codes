#include <iostream>
using namespace std;

int main() {
	int size, trace = 0;
	cout<<"Enter size of Square Matrix : ";
	cin>>size;
	int M[size][size], N[size][size];
	cout<<"Enter elements for the matrix 1 \n";
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			cout<<"Element "<<(i+1)<<","<<(j+1)<<" : ";
			cin>>M[i][j];
		}
	}
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}cout<<"\nEnter elements for the matrix 2\n";
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			cout<<"Element "<<(i+1)<<","<<(j+1)<<" : ";
			cin>>N[i][j];
		}
	}
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			cout<<N[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			if(i == j)
			trace += M[i][j];
		}
	}
	cout<<endl;
	int sum[size][size] = {0};
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			sum[i][j] = M[i][j] + N[i][j];
		}
	}
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	int diff[size][size] = {0};
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			diff[i][j] = M[i][j] - N[i][j];
		}
	}
	for(int i = 0; i < size; i ++){
		for(int j = 0; j < size; j ++){
			cout<<diff[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<trace;
    return 0;
}
