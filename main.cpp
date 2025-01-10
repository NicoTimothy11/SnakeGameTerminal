#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

int main() {

    int rows = 10, columns = 10;
    bool growing, gameOver;
    char ch;

    gameOver = false;

    vector<char> snakeBody = {'H', '0', '0'};
    vector<vector<char>> Grid(rows, vector<char>(columns, '*'));

    while(gameOver == false) {
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
                Grid[i][9] = '#';
                Grid[9][i] = '#';
                Grid[j][0] = '#';
                Grid[0][j] = '#';

                Grid[2][2] = snakeBody[2];
                Grid[2][3] = snakeBody[1];
                Grid[2][4] = snakeBody[0];

                cout << Grid[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Enter a key: ";
        cout << endl;
        ch = getch();

        if(ch == 'd') {
            Grid[2][2] = snakeBody[2];
            Grid[2][3] = snakeBody[1];
            Grid[2][4] = snakeBody[0];
        }
        if(ch == 'a') {
            gameOver = true;
            break;
        }
    }

    return 0; 
}