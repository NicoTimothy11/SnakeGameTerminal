#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Grid {
    public:
        int rows = 10;
        int columns = 10;
        static char board[rows * columns];
};

class Snake {
    public:
        int length;
};

class Game {
    public:
        Grid grid;

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
};

int main() {

    return 0; 
}