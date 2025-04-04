#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

//utility functions
void MakeGrid(char grid[][38], int x, int y);
void PrintGrid(char grid[][38], int x, int y);
int GetRandomBetween(int ceiling);

//hybrid functions
void PlayerMoves(char grid[][38], int rows, int columns, int &m1_x, int &m1_y, int &m2_x, int &m2_y, int &p_x, int &p_y);
void MonstersMove(char grid[][38], int rows, int columns, int &m1_x, int &m1_y, int &m2_x, int &m2_y, int &p_x, int &p_y);
//graphics-independent A.I. functions
void MoveHorizontaly(int &x, int xDim, bool right);
void MoveVertically(int &x, int xDim);
void PlayerMove(int &x, int &y, int xDim, int yDim);
void MonsterMove(int &x, int &y, int xDim);

int main()
{
    char grid[8][38];
    int m1_x = 15, m1_y = 1; //spawn coordinates of monster 1
    int m2_x = 25, m2_y = 6; //spawn coordinates of monster 2
    int p_x = 0, p_y = 1;   //spawn coordinates of A.I. player
    //set the graphics
    MakeGrid(grid, 8, 38);  //creates the grid, with two corridors
    grid[m1_y][m1_x]='(';
    grid[m1_y][m1_x+1]='^';
    grid[m1_y][m1_x+2]=')';
    grid[m2_y][m2_x]='(';
    grid[m2_y][m2_x+1]='^';
    grid[m2_y][m2_x+2]=')';
    grid[p_y][p_x]='{';
    grid[p_y][p_x+1]='}';

    PrintGrid(grid, 8, 38);

    srand(time(NULL));

    bool start = false;
    cin>>start;
    while(true)
    {
        PrintGrid(grid, 8, 38);//print grid in beginning of each iteration
        PlayerMoves(grid, 8, 38, m1_x, m1_y, m2_x, m2_y, p_x, p_y);  //check if fight will happen prior to moving
        MonstersMove(grid, 8, 38, m1_x, m1_y, m2_x, m2_y, p_x, p_y);  //check if fight will happen after moving

        if(p_x<2 && p_y==6) //check for termination conditions
        {
            cout<<"Simulation Terminated"<<endl;
            break;
        }
    }
    return 0;
}

void MakeGrid(char grid[][38], int x, int y)
{
    //initialize
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            grid[i][j]=' ';

    //make horizontal edge of all hallways
    for(int j=0; j<(y-1);j++)
    {
        grid[0][j]='-';
        grid[7][j]='-';
    }

     for(int j=0; j<(y-4);j++)
     {
        grid[2][j]='-';
        grid[5][j]='-';
     }

    //make right most vertical edge
    for(int i=0; i<x; i++)
        grid[i][y-1]='|';
    for(int i=2; i<=5; i++)
        grid[i][34]='|';
}

void PrintGrid(char grid[][38], int x, int y)
{
    system("cls");
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
             cout<<grid[i][j];
        }
        cout<<endl;
    }
}

void MonstersMove(char grid[][38], int rows, int columns, int &m1_x, int &m1_y, int &m2_x, int &m2_y, int &p_x, int &p_y)
{
   //FLL THIS FUNCTION
    //if (m1_x)
    for(int j=0; j<columns-1; j++)
    {
        grid[1][j]=' '; //reset the values of across the entirety of the corridors
        grid[6][j]=' '; //thus deleting graphics of player and monsters alike, that way we dont have to worry about passing their coordinates
    }

    for(int i=0; i<rows-1; i++)
    {
        grid[i][columns-3]=' '; //reset the values of across the entirety of the corridors
        grid[i][columns-2]=' '; //thus deleting graphics of player and monsters alike, that way we dont have to worry about passing their coordinates
    }


     if(GetRandomBetween(2)==1)
     {
         if(m2_x>1 && m2_x != -1)
             m2_x--;

         if(m1_x>1 && m1_x != -1)
             m1_x--;
     }
    else
    {
             if(m2_x<columns-6 && m2_x != -1)
                m2_x++;

             if(m1_x<columns-6 && m1_x != -1)
                m1_x++;
    }



    grid[m1_y][m1_x]='(';
    grid[m1_y][m1_x+1]='^';
    grid[m1_y][m1_x+2]=')';
    grid[m2_y][m2_x]='(';
    grid[m2_y][m2_x+1]='^';
    grid[m2_y][m2_x+2]=')';
    grid[p_y][p_x]='{'; //update graphic values for player
    grid[p_y][p_x+1]='}';
    PrintGrid(grid, 8, 38);

     if(p_x == (m1_x-3) &&  p_y == 1 && m1_x != -1)//if no distance between player and monster 1
    {
        for(int i=0; i<10; i++)//animation
        {
            grid[p_y][p_x+2]='/';
            PrintGrid(grid, 8, 38);
            grid[p_y][p_x+2]='-';
            PrintGrid(grid, 8, 38);
        }
        if(GetRandomBetween(10)>5)//player wins
        {
            m1_x=-1;
            m1_y=-1;
            grid[m1_y][m1_x]=' ';
            grid[m1_y][m1_x+1]=' ';
        }
        else //player loses
        {
            p_x=0;
            p_y=1;
        }
    }
    else if(p_x ==(m2_x+4) && p_y == 6 && m2_x != -1) //or monster 2 respectively
    {
        for(int i=0; i<10; i++)
        {
            grid[p_y][p_x-1]='\\';
            PrintGrid(grid, 8, 38);
            grid[p_y][p_x-1]='-';
            PrintGrid(grid, 8, 38);
        }
        if(GetRandomBetween(10)>6)//player wins
        {
            m2_x=-1;
            m2_y=-1;
            grid[m2_y][m2_x]=' ';
            grid[m2_y][m2_x+1]=' ';
        }
        else //player loses
        {
            p_x=0;
            p_y=1;
        }
    }


}


int GetRandomBetween(int ceiling)
{
    int temp= rand() % ceiling;
    return temp;
}

void MoveHorizontaly(int &x, int xDim, bool right)
{
    if(GetRandomBetween(10)>7 )//smaller chance
    {
        if(x>1 && right == true)//can't move beyond the grid
            x--;
        else if(x<(xDim-3) && right == false)
            x++;
    }
    else //big chance
    {
        if(x<xDim-3 && right == true)//can't go beyond the grid
           x++;
        else if( x>1 &&  right == false)
            x--;
    }
}

void MoveVertically(int &y, int yDim)
{
    if(GetRandomBetween(10)>7)
    {
        if(y>1)//can't move beyond the grid
            y--;
    }
    else //move right
    {
        if(y<yDim-2)//can't go beyond the grid
             y++;
    }
}

void PlayerMoves(char grid[][38], int rows, int columns, int &m1_x, int &m1_y, int &m2_x, int &m2_y, int &p_x, int &p_y)
{
    //reset graphics
    for(int j=0; j<columns-1; j++)
    {
        grid[1][j]=' '; //reset the values of across the entirety of the corridors
        grid[6][j]=' '; //thus deleting graphics of player and monsters alike, that way we dont have to worry about passing their coordinates
    }

    for(int i=0; i<rows-1; i++)
    {
        grid[i][columns-3]=' '; //reset the values of across the entirety of the corridors
        grid[i][columns-2]=' '; //thus deleting graphics of player and monsters alike, that way we dont have to worry about passing their coordinates
    }

    //player moves
    if(p_x<columns-3 || p_y == 6) //if on second corridor and x-coordinate is small
    {
        if(p_y==1) //if one first corridor but not on the far right,  always move right
           MoveHorizontaly(p_x, columns, true);
        else    //if we are on 2nd corridor move left
           MoveHorizontaly(p_x, columns, false);
    }
    else if(p_x >= columns-3)//else move vertically
        MoveVertically(p_y, rows);

    //update graphics
    grid[m1_y][m1_x]='(';
    grid[m1_y][m1_x+1]='^';
    grid[m1_y][m1_x+2]=')';
    grid[m2_y][m2_x]='(';
    grid[m2_y][m2_x+1]='^';
    grid[m2_y][m2_x+2]=')';
    grid[p_y][p_x]='{'; //update graphic values for player
    grid[p_y][p_x+1]='}';

    if(p_x == (m1_x-3) &&  p_y == 1 && m1_x != -1)//if no distance between player and monster 1
    {
        for(int i=0; i<10; i++)//animation
        {
            grid[p_y][p_x+2]='/';
            PrintGrid(grid, 8, 38);
            grid[p_y][p_x+2]='-';
            PrintGrid(grid, 8, 38);
        }
        if(GetRandomBetween(10)>5)//player wins
        {
            m1_x=-1;
            m1_y=-1;
            grid[m1_y][m1_x]=' ';
            grid[m1_y][m1_x+1]=' ';
        }
        else //player loses
        {
            p_x=0;
            p_y=1;
        }
    }
    else if(p_x ==(m2_x+4) && p_y == 6 && m2_x != -1) //or monster 2 respectively
    {
        for(int i=0; i<10; i++)
        {
            grid[p_y][p_x-1]='\\';
            PrintGrid(grid, 8, 38);
            grid[p_y][p_x-1]='-';
            PrintGrid(grid, 8, 38);
        }
        if(GetRandomBetween(10)>6)//player wins
        {
            m2_x=-1;
            m2_y=-1;
            grid[m2_y][m2_x]=' ';
            grid[m2_y][m2_x+1]=' ';
        }
        else //player loses
        {
            p_x=0;
            p_y=1;
        }
    }
    PrintGrid(grid, 8, 38);//print grid in beginning of each iteration
}
