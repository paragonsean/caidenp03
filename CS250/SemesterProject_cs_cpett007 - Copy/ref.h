#ifndef REF_H_INCLUDED
#define REF_H_INCLUDED
#include "player.h"
#include "board.h"
#include <iostream>

using namespace std;

class referee
{
    public:
        referee();
        referee(board &b);
        bool checkValidPlayer(board &b, int y, int x, int i);
        bool checkIfCaptured(board &b, int y, int x, int i);
        bool checkEnemy(board &b, int y, int x, int i);
        bool checkForBypass(board &b, int y1, int x1, int y2, int x2);
        bool checkForOneDir(board &b, int y1, int x1, int y2, int x2);
        bool checkIfMoveisValid(board &b, int y1, int x1, int y2, int x2, int i);
        bool checkEndConditions(board &b);

    private:
        board b;
        int score[2];

};

#endif // REF_H_INCLUDED
