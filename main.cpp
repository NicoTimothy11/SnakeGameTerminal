#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int main() {
    bool gameOver = false;
    char ch;

    const int rows = 20;
    const int columns = 20;

    while(gameOver == false) {
        int array[rows][columns] = { 0 };

        cout << "Enter a character to move: ";
        ch = getch();
        cout << endl;
        array[5][3] = 3;

        if(ch == 'd') 
        {
            for (int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++)
                {
                    array[5][3 + 1];
                }
            }
        }
        if(ch == 'a') {
            break;
        }        


        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
        
        if(gameOver = true) {
            break;
        }
    }
    return 0; 
}