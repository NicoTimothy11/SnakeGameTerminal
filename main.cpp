#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

bool isGameOver = false;

class SnakePart {
    public:
        int x;
        int y;
};

class Snake {
    public:
        static const int SnakeLength = 256;
        int length;
        SnakePart body[SnakeLength];
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
            //board[snake.snakeY][snake.snakeX] = '@';
            for(int i = snake.length-1; i > 0; i--) {
                board[snake.body[i].y][snake.body[i].x] = '*';
            }
            board[snake.body[0].y][snake.body[0].x] = '@';
        }

        void moveSnake(int dx, int dy) {
            snake.body[0].x += dx;
            snake.body[0].y += dy;
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
        Snake snake;
        
        snake.length = 1;
        snake.body[0].x = 5;
        snake.body[1].y = 5;


        while(!isGameOver) {
            game.fillBoard();
            game.DrawSnake();
            game.clearScreen();
            game.printBoard();
            game.HandleInput();
        }

        return 0;
    }