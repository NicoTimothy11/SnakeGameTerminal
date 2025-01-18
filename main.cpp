#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;


class Snake {
    public:
        int length = 256;
        int x;
        int y;
        int part[];

        Snake() {
            part[length];
        }
};

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

        void handleInput() {
            int ch = getch();

            switch(ch) {
                case 'w' : HandleInput(0, -1); break;
                case 'a' : HandleInput(0, 1); break;
                case 's' : HandleInput(-1, 0); break;
                case 'd' : HandleInput(1, 0); break;
        
            }
        }

        void DrawSnake() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if(i == 3 && j == 3) {
                        board[i][j] = '@';
                    }
                }
            }
        }

        void HandleInput(int dx, int dy) {
            snake.x += dx;
            snake.y += dy;
        }

};


int main() {
    Grid grid;

    grid.DrawSnake();
    grid.printBoard();
    grid.handleInput();
    return 0; 
}