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
    float random();
    void avg();
};
//struct with variables and member functions

void intxt();
void output();
void outtxt();
//functions to read and output file information

particle::particle()
{

}

void intxt()
{
    ifstream infile;
    infile.open("unfiltered.txt");
    if (!infile) //there was an error on open, file not found
        { cout << "Cannot open file, terminating program"<< endl;
        exit (1); }
    particle point;
    while (infile)
    {
      for (int i=0; i<1000; i++)
    {
        infile >> point.id[i] >> point.cX[i] >> point.cY[i] >> point.cZ[i]
                >> point.xSize[i] >> point.ySize[i] >> point.zSize[i]
                >> point.sVar[i] >> point.rival_id[i];
                if (point.cX[i] > 70)
                    point.cX[i] = 70;
                if(point.cY[i] > 60)
                    point.cY[i] = 60;
                if (point.cZ[i] > 50)
                    point.cZ[i] = 50;
    }
    }
//opens the file and reads the values assigning them to the coresponding variables
    infile.close();
}

void particle::avg()
{
    particle point;
    intxt();
    float xCoorAvg;
    float yCoorAvg;
    float zCoorAvg;
    float xSizeAvg;
    float ySizeAvg;
    float zSizeAvg;

    for (int i=0; i<1000; i++)
    {
        xCoorAvg += point.cX[i];
        yCoorAvg += point.cY[i];
        zCoorAvg += point.cZ[i];
        xSizeAvg += point.xSize[i];
        ySizeAvg += point.ySize[i];
        zSizeAvg += point.zSize[i];
    }
    xCoorAvg = xCoorAvg/1000;
    yCoorAvg = yCoorAvg/1000;
    zCoorAvg = zCoorAvg/1000;
    xSizeAvg = xSizeAvg/1000;
    ySizeAvg = ySizeAvg/1000;
    zSizeAvg = zSizeAvg/1000;
//formula for the average of each variable
    cout << "Average x-coordinate:    " << xCoorAvg << endl;
    cout << "Average y-coordinate:    " << yCoorAvg << endl;
    cout << "Average z-coordinate:    " << zCoorAvg << endl;
    cout << "Average x-size:          " << xSizeAvg << endl;
    cout << "Average y-size:          " << ySizeAvg << endl;
    cout << "Average z-size:          " << zSizeAvg << endl;
//outputs the average variables
}

void output()
{
    particle point;
    int temp;
    for (int i=0; i<1000; i++)
    {
        /*for (int j=0; j<1000; j++)
        {
            if (point.id[i] > point.id[j])
            {
                temp = point.id[j];
                point.id[i] = temp;
                point.id[j] = point.id[i];

            }*/
        cout << point.id[i] << " " << fixed << setprecision(4)
             << point.cX[i] << " " << point.cY[i] << " " << point.cZ[i] << " "
             << point.xSize[i] << " " << point.ySize[i] << " " << point.zSize[i] << " "
             << point.sVar[i] << " " << point.rival_id[i] << endl;
        }

    point.avg();
}
//outputs to the command screen

void outtxt()
{
    ofstream myfile;
    myfile.open ("filtered.txt");
    particle point;
    intxt();

 for (int i=0; i<1000; i++)
    {
        myfile << point.id[i] << " " << fixed << setprecision(2)
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
    intxt();
    output();
    outtxt();
    return 0;
    //srand time makes the rand always different, also outputs to the text file
}
