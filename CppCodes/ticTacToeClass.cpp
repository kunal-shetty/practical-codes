#include <iostream>

using namespace std;

class Game {
private:
    char board[3][3];  // 3x3 board
    char currentPlayer; // 'X' or 'O'

public:
    // Constructor
    Game() {
        currentPlayer = 'X';
        initializeBoard();
    }

    // Initialize the board with numbers
    void initializeBoard() {
        char num = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = num++;
            }
        }
    }

    // Display the board
    void displayBoard() {
        cout << "\nTic-Tac-Toe Game\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }
        cout << endl;
    }

    // Player move
    bool makeMove(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move! Try again.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    // Check for a winner
    bool checkWin() {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    // Check if the board is full
    bool isDraw() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    // Switch to the next player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Start the game
    void startGame() {
        int position;
        displayBoard();

        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> position;

            if (!makeMove(position)) continue;

            displayBoard();

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

// Main function
int main() {
    Game ticTacToe;
    ticTacToe.startGame();
    return 0;
}
