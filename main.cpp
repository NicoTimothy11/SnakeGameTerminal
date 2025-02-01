#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

bool isGameOver = false;

class Snake {
    public:
        static const int SnakeLength = 256;
        int length;
        int snakeX = 5;
        int snakeY = 5;
};



class Game {
    protected:
        static const int rows = 20;
        static const int columns = 20;
        char board[rows][columns];
        Snake snake;

    public:

        Game() {
            for (int i = 0; i < columns; i++) {
                for (int j = 0; j < columns; j++) {
                        board[i][j] = ' ';
                    }
                }
            }
        
        void fillBoard() {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    if(i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                        board[i][j] = '#';
                    }
                    else {
                        board[i][j] = ' ';
                    }
                }
            }
        }

        void printBoard() {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }

        void DrawSnake() {
            board[snake.snakeY][snake.snakeX] = '@';
        }

        void moveSnake(int dx, int dy) {
            snake.snakeX += dx;
            snake.snakeY += dy;
        }

        void HandleInput() {
            char ch = getch();

            switch(ch) {
                case 'w': moveSnake(0, -1); break;
                case 's': moveSnake(0, 1); break;
                case 'a': moveSnake(-1, 0); break;
                case 'd': moveSnake(1, 0); break; 
            }
        }
        
        void clearScreen() {
            system("cls");
        }

    };


    int main() {
        Game game;

        while(!isGameOver) {
            game.fillBoard();
            game.DrawSnake();
            game.clearScreen();
            game.printBoard();
            game.HandleInput();
        }

        return 0;
    }