#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int rows = 10, columns = 10;

    vector<int> snakeBody = {0, 0, 0};

    vector<vector<char>> Grid(rows, vector<char>(columns, '*'));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << Grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0; 
}