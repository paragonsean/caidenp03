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

        void setScore(int i);//a set and get for score
        int getScore(int i){return score[i];}
        bool checkValidPlayer(board &b, int y, int x, int i);
        bool checkEnemy(board &b, int y, int x, int i);
        bool checkForBypass(board &b, int y1, int x1, int y2, int x2);
        bool checkForOneDir(board &b, int y1, int x1, int y2, int x2);
        bool checkIfMoveisValid(board &b, int y1, int x1, int y2, int x2, int i);
        bool checkEndConditions();
        void checkIfCaptured(board &b, int y, int x, int i, char a, char A, char B);
        bool checkDuke(board &b, int y, int x, int i, char a, char A);
        void checkDukegone(board &b, int x, int y, int i, char a, char A);
        bool checkCrossCapture(board &b, int y, int x, char a, char A, char B);

    private:

        int score[2];

};

#endif // REF_H_INCLUDED
