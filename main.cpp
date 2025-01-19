#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

bool isGameOver = false;

class SnakePart {
    public:
        int x, y;
};

class Snake {
    public:
        int length = 256;
        int x = 2;
        int y = 2;
        static int part[];

        Snake() {
            part[length];
        }
};

class Grid {
    protected:
        static const int rows = 20;
        static const int columns = 20;
        char board[rows][columns];
        Snake snake;

    public:

        Grid() {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                        board[i][j] = ' ';
                    }
                }
        }

        void fillBoard() {
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

            for(int i = snake.length-1; i > 0; i--) {
                board[snake.part[0]][snake.part[0]] = '*';
            }
            board[snake.x][snake.y] = '@';
        }

        void MoveSnake(int dx, int dy) {
            snake.x += dx;
            snake.y += dy;
        }

        void handleInput() {
            char ch = getch();

            switch(ch) {
                case 'w' : MoveSnake(-1, 0); break;
                case 'a' : MoveSnake(0, -1); break;
                case 's' : MoveSnake(1, 0); break;
                case 'd' : MoveSnake(0, 1); break;
                case 'q' : isGameOver = true; break;
        
            }
        }

        void ClearScreen() {
            system("cls");
        }

};


int main() {
    Grid grid;

    while(!isGameOver) {
        grid.printBoard();
        grid.fillBoard();
        grid.DrawSnake();
        grid.handleInput();
        grid.ClearScreen();
    }
    return 0; 
}