    #include <iostream>
    #include <cstdlib>
    #include <conio.h>
    #include <chrono>
    #include <thread>

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

            int getLength() {
                return length;
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

            Game() {
                for (int i = 0; i < 20; i++) {
                    for (int j = 0; j < 20; j++) {
                            board[i][j] = ' ';
                        }
                    }
            }

            void fillBoard() {
                for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                    board[i][j] = '#';
                } else {
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

                for(int i = 1; i < snake.getLength(); i++) {
                    SnakePart part = snake.getPart(i);
                    board[part.y][part.x] = '*';
                }
                board[snake.getHead().y][snake.getHead().x] = '@';
            }

            void gameRules() {
                isGameOver = false;
                SnakePart& head = snake.getHead();
                if(head.x == 0 || head.x == columns - 1 || head.y == 0 || head.y == rows -1 ) {
                    isGameOver = true;
                }
                if(snake.collideWithSelf()) {
                    isGameOver = true;
                }
            }

            void handleInput() {

                if(_kbhit()) {
                    char ch = getch();

                    switch(ch) {
                        case 'w' : snake.move(0, -1); break;
                        case 'a' : snake.move(-1, 0); break;
                        case 's' : snake.move(0, 1); break;
                        case 'd' : snake.move(1, 0); break;
                        case 'q' : isGameOver = true; break;
                    }
                }
            }

            void ClearScreen() {
                system("cls");
            }

            void Run() {
                while(!isGameOver) {
                    fillBoard();
                    DrawSnake();
                    gameRules();
                    ClearScreen();
                    printBoard();
                    handleInput();
                    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }

                cout << "Game Over" << endl;
            }

    };


    int main() {
        Game game;
        game.Run();
        return 0; 
    }