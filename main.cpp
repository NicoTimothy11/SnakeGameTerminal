#include <iostream>
#include <vector>
#include <cstdlib.h>
#include <conio.h>

using namespace std;

class Grid {
    public:
        int rows = 10;
        int columns = 10;
};

class Snake {
    public:
        int length;
};

class Game {
    public:
        void HandleUpdate();
        void DrawBoard();
        void ClearScreen();
};

int main() {

    return 0; 
}