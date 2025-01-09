#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

int main() {

    const int rows = 10;
    const int columns = 10;

        char* array[rows][columns] = {'*'};

        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    return 0; 
}