#include <iostream>
#include <cstdlib>
#include <conio.h>

bool isGameOver = false;

using namespace std;

class Food {
public:
    int x, y;
    int consumed;
};

class SnakePart {
public:
    int x, y;
};

class Snake {
    public:
        static const int SnakeLength = 256;
        int length = 0;
        SnakePart body[SnakeLength];
};



class Game {
    protected:
        static const int rows = 20;
        static const int columns = 20;
        static const int foods = 50; 
        char board[rows][columns];
        Food food[foods];
        Snake snake;


    public:
        Game() {
            fillBoard();
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
            for(int i = 1; i < snake.length; i++) {
                board[snake.body[i].y][snake.body[i].x] = '*';
            }
            board[snake.body[0].y][snake.body[0].x] = '@';
        }

        void moveSnake(int dx, int dy) {

            for(int i = snake.length-1; i > 0; i-- ) {
                snake.body[i] = snake.body[i-1];
            }
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
                case 'q': isGameOver = true; break;
            }
        }
        
        void clearScreen() {
            system("cls");
        }

        void GameRules() {
            for(int i = 0; i < foods; i++) {
                if(!food[i].consumed) {
                    if(food[i].x == snake.body[0].x && food[i].y == snake.body[0].y) {
                        food[i].consumed = 1;
                        snake.length++;
                    }
                }
            }

            for(int i = 1; i < snake.length; i++) {
                if(snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                    isGameOver = true;
                    cout << "Game Over, Snake bit itself";
                }
            }

            if(snake.body[0].x == 0 || snake.body[0].x == columns - 1 
            || snake.body[0].y == 0 || snake.body[0].y == rows - 1) {
                isGameOver = true;
                cout << "Game Over, Snake hit the wall.";
            }
        }

        void FoodSetUp() {
            for(int i = 0; i < foods; i++) {
                food[i].x = 1 + rand() % (columns - 2);
                food[i].y = 1 + rand() % (rows - 2);
                food[i].consumed = 0;
            }
        }

        void SnakeSetUp() {
            snake.length = 1;
            snake.body[0].x = 1 + rand() % (columns - 2);
            snake.body[0].y = 1 + rand() % (rows - 2);
        }

        void DrawFood() {
            for(int i = 0; i < foods; i++) {
                if(!food[i].consumed) {
                    board[food[i].y][food[i].x] = '+';
                }
            }
        }

    };


    int main() {
        Game game;
        srand(time(0));

        game.SnakeSetUp();
        game.FoodSetUp();

        while(!isGameOver) {
            game.fillBoard();
            game.DrawFood();
            game.DrawSnake();
            game.clearScreen();
            game.printBoard();
            game.GameRules();
            if(!isGameOver) game.HandleInput();
        }

        return 0;
    }