#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int main() {
    bool gameOver = false;
    char ch;

    const int rows = 10;
    const int columns = 10;

        int array[rows][columns] = { 0 };
        int x = 5;
        int y = 3;
        array[x][y] = 3;

        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }

    while(gameOver == false) {

        cout << "Enter a character to move: ";
        ch = getch();
        
        cout << endl;
        while(ch = 'd') {
            ch = getch();

            for (int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++)
                {
                    array[i][j] = array[i][j + 1];
                    cout << array[i][j] << " ";
                }
                cout << endl;
            }

            if(ch == 'a') {
            break;
            }  
        }
              


        /*for (int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        } */
        
        if(gameOver = true) {
            break;
        }
    }
    return 0; 
}