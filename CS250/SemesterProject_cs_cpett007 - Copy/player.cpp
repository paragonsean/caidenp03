#include "player.h"

player::player()
{

}
player::player(board &b)
{
    p1DukeX = 9;
    p1DukeY = 4;
    p2DukeX = 11;
    p2DukeY = 14;
    b.makePlayers(p1DukeY, p1DukeX, p1DukeC);
    b.makePlayers(p2DukeY, p2DukeX, p2DukeC);

    int tempX = 0;
    int tempY = 0;

        for(int i = 1; i < 9; i++)
        {
            p1PawnX[i-1] = (2*i)+1;
            p1PawnY[i-1] = 2;
            tempX = p1PawnX[i-1];
            tempY = p1PawnY[i-1];
            b.makePlayers(tempY,tempX,p1PawnC);
        }
                for(int i = 1; i < 9; i++)
        {
            p2PawnX[i-1] = (2*i)+1;
            p2PawnY[i-1] = 16;
            tempX = p2PawnX[i-1];
            tempY = p2PawnY[i-1];
            b.makePlayers(tempY,tempX,p2PawnC);
        }
}

void player::movePlayer(board &b, int x1, int y1, int x2, int y2, int i)
{
        switch(i)
        {
        case 0:
            if(b.getGrid(y1, x1) == 'O')
                b.updateBoard(y1, x1, y2, x2, p1DukeC);
            else
                b.updateBoard(y1, x1, y2, x2, p1PawnC);
            break;
        case 1:
            if(b.getGrid(y1, x1) == 'X')
                b.updateBoard(y1, x1, y2, x2, p2DukeC);
            else
                b.updateBoard(y1, x1, y2, x2, p2PawnC);
            break;
        }
    b.printBoard();
}
