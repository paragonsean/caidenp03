#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "player.h"
#include "board.h"
#include "ref.h"
#include <iostream>
using namespace std;

class player
{
    public:
        player();
        player(board &b);
        void movePlayer(board &b, int x1, int y1, int x2, int y2, int i);

    private:
        //referee r;
        board b;

        int p1DukeX;
        int p1DukeY;
        int p1PawnX[8];
        int p1PawnY[8];
        int p2DukeX;
        int p2DukeY;
        int p2PawnX[8];
        int p2PawnY[8];

        char p1DukeC = 'O';
        char p1PawnC = 'o';
        char p2DukeC = 'X';
        char p2PawnC = 'x';

};
#endif // PLAYER_H_INCLUDED
