#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

bool isGameOver = false;

class SnakePart {
    public:
        int x, y;
        SnakePart(int x = 0, int y = 0) : x(x), y(y) {}
};

class Snake {
    public:
        static const int SnakeLength = 256;
        int length;
        SnakePart parts[SnakeLength];

        Snake() {
            length = 1;
            parts[0].x = 1 + rand() % (20 - 2);
            parts[0].y = 1 + rand() % (20 - 2);

            for(int i = 1; i < SnakeLength; i++) {
                parts[i].x = 0;
                parts[i].y = 0;
            }
        }

        SnakePart& getHead() {
            return parts[0];
        }

        SnakePart& getPart(int index){
            return parts[index];
        }

        void move(int dX, int dY) {
            for(int i = length - 1; i > 0; i--) {
                parts[i] = parts[i - 1];
            }
            parts[0].x += dX;
            parts[0].y += dY;
        }

        void grow() {
            if(length < SnakeLength) {
                parts[length] = parts[length - 1];
                length++;
            }
        }

        bool collideWithSelf() {
            for(int i = 1; i < length; i++) {
                if(parts[0].x == parts[i].x & parts[0].y == parts[i].y ) {
                    return true;
                }
            }
            return false;
        }

};



class Game {
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
    Game *game;

    while(!isGameOver) {
        game->ClearScreen   ();
        game->DrawSnake();
        game->printBoard();
        game->handleInput();
        game->ClearScreen();
    }
    return 0; 
}