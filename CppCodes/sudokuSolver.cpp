#include <iostream>
#include <windows.h>
#define N 9    
using namespace std;

void printGrid(int grid[N][N]) {
    system("cls");  
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (grid[i][j] == 0)
                cout<<"_ ";
            else
                cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    Sleep(10); 
}

bool isValid(int grid[N][N], int row, int col, int num) {
    for(int i = 0; i < N; i++)
        if(grid[row][i] == num)
            return false;
    for(int i = 0; i < N; i++)
        if(grid[i][col] == num)
            return false;
    int startRow = row - row % 3,
	    startCol = col - col % 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(grid[startRow + i][startCol + j] == num)
                return false;
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = false;

    for(row = 0; row < N; row++) {
        for(col = 0; col < N; col++) {
            if(grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if(isEmpty) break;
    }
    if(!isEmpty) return true;
    for(int num = 1; num <= 9; num++) {
        if(isValid(grid, row, col, num)) {
            grid[row][col] = num;  
            printGrid(grid); 
            if(solveSudoku(grid)) 
                return true;
            grid[row][col] = 0;  
            printGrid(grid); 
        }
    }
    return false;  
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 2, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 1, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 7, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    solveSudoku(grid);

    return 0;
}
