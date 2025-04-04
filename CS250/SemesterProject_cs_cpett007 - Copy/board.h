#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>

using namespace std;

class board
{
    public:
        board();
        void makeBoard();
        void makePlayers(int y, int& x, char a);
        void updateBoard(int oldY, int oldX, int y, int x, char a);
        void printBoard();
        char getGrid(int y, int x);


    private:
        char grid[18][19];
};


#endif // BOARD_H_INCLUDED
