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

        void DrawSnake() {}
            

    };


    int main() {
        Game game;
        game.fillBoard();
        game.printBoard();
    }