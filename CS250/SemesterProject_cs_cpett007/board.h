#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>

using namespace std;

class board
{
    public:

        board();//constuctor of class board

        void makeBoard();//generate funciton
        char getGrid(int y, int x);
        void makePlayers(int y, int x, char a);//generate the players and set grid
        void updateBoard(int oldY, int oldX, int y, int x, char a);//reset the board and generate fresh field
        void printBoard();//print board function

    private:

        char grid[18][19];//grid size to include the lines and boarders
};


#endif // BOARD_H_INCLUDED
