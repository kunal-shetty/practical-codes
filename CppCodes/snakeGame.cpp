#include <iostream>
#include <conio.h>  // For _kbhit() and _getch()
#include <windows.h>  // For Sleep()
#include <cstdlib>  // For rand()
using namespace std;

bool gameOver;
int width = 20, height = 10;
int x, y, fruitX, fruitY, score;
char direction;

void Setup() {
    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls");  // Clear screen

    // Draw top border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";  // Left border

            if (i == y && j == x) 
                cout << "O";  // Snake head
            else if (i == fruitY && j == fruitX) 
                cout << "F";  // Food
            else 
                cout << " ";

            if (j == width - 1) cout << "#";  // Right border
        }
        cout << endl;
    }

    // Draw bottom border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << "\nScore: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': y--; break;
            case 's': y++; break;
            case 'a': x--; break;
            case 'd': x++; break;
            case 'x': gameOver = true; break;
        }
    }
}

void Logic() {
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
    if (x >= width || x < 0 || y >= height || y < 0) 
        gameOver = true;  // Game over if snake hits the wall
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);  // Adjust speed
    }
    cout << "Game Over! Final Score: " << score << endl;
    return 0;
}
