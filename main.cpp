#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Grid {
    protected:
        int rows = 20;
        int columns = 20;
        char board[20][20];
        Snake snake;

    public:
        Grid() {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                        if(i == 0 || i == rows-1 || j == 0 || j == columns-1) {
                            board[i][j] = '#';
                        }
                        else {
                            board[i][j] = ' ';
                        }
                    }
                }
            }

        void printBoard() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }

        void MoveSnake(int dx, int dy) {
            snake.x += dx;
            snake.y += dy;
        }

        void handleInput() {
            char ch = getch();

            switch(ch) {
                case 'w' :
                case 'a' :
                case 's' :
                case 'd' :
            }
        }
};

class Snake {
    public:
        int length;
        int x;
        int y;
        int part[256];
};


int main() {
    Grid grid;

    grid.printBoard();
    return 0; 
}