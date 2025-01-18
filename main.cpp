#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

bool isGameOver = false;

class Snake {
    public:
        int length = 256;
        int x = 2;
        int y = 2;
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


        void DrawSnake() {
            board[snake.x][snake.y] = '@';
        }

        void MoveSnake(int dx, int dy) {
            snake.x += dx;
            snake.y += dy;
        }

        void handleInput() {
            int ch = getch();

            switch(ch) {
                case 'w' : MoveSnake(0, 1); break;
                case 'a' : MoveSnake(0, 1); break;
                case 's' : MoveSnake(-1, 0); break;
                case 'd' : MoveSnake(1, 0); break;
                case 'q' : isGameOver = true; break;
        
            }
        }

};


int main() {
    Grid grid;

    while(!isGameOver) {
        grid.printBoard();
        grid.DrawSnake();
        grid.handleInput();
    }
    return 0; 
}