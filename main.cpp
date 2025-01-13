#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Grid {
    protected:
        int rows = 20;
        int columns = 20;
        char board[20][20];

    public:
        Grid() {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                        board[i][j] = ' ';
                        board[19][j] = '#';
                        board[0][j] = '#';
                        board[i][19] = '#';
                        board[i][0] = '#';
                    }
                }
            }

        void printBoard() {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }
};

class Snake {
    public:
        int length;
};

/*class Game {
    public:
        Grid grid;
        grid.board[grid.rows * grid.columns];

        void DrawBoard() {
            for (int x = 0; x < grid.rows; x++) {
                for (int y = 0; y < grid.columns; y++) {
                    if(x == 0 || y == 0 || x == grid.columns - 1 || y == grid.rows - 1) {
                        
                    }
                }
            }
        };
        void HandleUpdate();
        void ClearScreen();
};*/

int main() {
    Grid grid;

    grid.printBoard();
    return 0; 
}