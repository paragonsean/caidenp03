#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <random>
//libraries to use functions

using namespace std;

struct particle{
    particle();
    int id[1000];
    int rival_id[1000];
    float cX[1000];
    float cY[1000];
    float cZ[1000];
    float xSize[1000];
    float ySize[1000];
    float zSize[1000];
    string sVar[1000];

    float getRand(int cel);
    int genId();
    float random();
    int genRId();
    void genCoords();
    void genSize();
    void genVar(string sVar);
};
//struct with variables and member functions

void output();
void outtxt();
//two functions to include in main

particle::particle()
{

}
//constructor to enable particle

float particle::random()
{
    for (int i=0; i<1000; i++)
    {
        string temp;
        int w;
        w = getRand(7)+8;
        temp = "abcdefghijklmnopqrstuvwxyz";//possible characters
        for(int j = 0; j < w; j++)
        {
            sVar[i].push_back(temp[static_cast <int>(getRand(26))]);
            //add characters to the list sVar
        }
    }
}
//generate a random string 8 to 15 characters in length

int particle::genRId()
{
    getRand(2000);
    for (int i=0; i<1000; i++)
    {
        rival_id[i] = getRand(2000);
        for (int p=0; p<1000; p++)
        {
            if(p != i)
            {
                if (rival_id[i] == rival_id[p])
                i--;
                //if the ID is the same, redo the random generation
            }
        }
    }
}
//makes sure rival ID is unique from all others and is randomly generated

void particle::genCoords()
{
    for (int i=0; i<1000; i++)
    {
        cX[i] = getRand(100);
        cY[i] = getRand(75);
        cZ[i] = getRand(60);
    }
}
//random X Y Z coords

void particle::genSize()
{
    for (int i=0; i<1000; i++)
    {
        xSize[i] = getRand(10);
        ySize[i] = getRand(10);
        zSize[i] = getRand(10);
    }
}
//random X Y Z sizes

float particle::getRand(int cel)
{
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/cel));
}
//makes a random float for get rand function

int particle::genId()
{
    getRand(2000);
    for (int i=0; i<1000; i++)
    {
        id[i] = getRand(2000);
    }
    return false;
}
//generates a random float for each ID

void output()
{
    particle point;
    point.genId();
    point.genCoords();
    point.genSize();
    point.random();
    point.genRId();
    //includes the functions and initializes point
    for (int i=0; i<1000; i++)
    {
        cout << point.id[i] << " " << fixed << setprecision(4)
             << point.cX[i] << " " << point.cY[i] << " " << point.cZ[i] << " "
             << point.xSize[i] << " " << point.ySize[i] << " " << point.zSize[i] << " ";
        cout << point.sVar[i] << " " << point.rival_id[i] << endl;
    }
}
//outputs to the command screen 100 lists

void outtxt()
{
    ofstream myfile;
    myfile.open ("unfiltered.txt");
    particle point;
    point.genId();
    point.genCoords();
    point.genSize();
    point.random();
    point.genRId();
 for (int i=0; i<1000; i++)
    {
        myfile << point.id[i] << " " << fixed << setprecision(4)
               << point.cX[i] << " " << point.cY[i] << " " << point.cZ[i] << " "
               << point.xSize[i] << " " << point.ySize[i] << " " << point.zSize[i] << " ";
        myfile << point.sVar[i] << " " << point.rival_id[i] << endl;
    }
    myfile.close();
}
//outputs to the named file the same as the output screen

int main()
{
    srand(time(0));
    output();
    outtxt();
    return 0;
    //srand time makes the rand always different, also outputs to the text file
}
