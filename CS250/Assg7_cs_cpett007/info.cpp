#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "info.h"
#include "info2.h"
//header libraries
using namespace std;
//setter and getter functions to assign values to all the functions

void roads::setName(string road_name)
{
    name = road_name;
}

void roads::setroadLength(double road_length)
{
    roadLength = road_length;
}

void roads::setoneWay(bool one_way)
{
    oneWay = one_way;
}

void roads::setspeedLimit(int speed_limit)
{
    speedLimit = speed_limit;
}

string roads::getName()
{
    return name;
}

double roads::getroadLength()
{
    return roadLength;
}

bool roads::getoneWay()
{
    return oneWay;
}

int roads::getspeedLimit()
{
    return speedLimit;
}
//a multipurpose read function to assign and output the values from the getter and setter functions

void roads::readR()
{
    int index;
    ifstream myfile;
    myfile.open("roads.txt");
    if(myfile.fail())//incase it doesn't read
    {
        cout << "file fail." << endl;
        exit(1);
    }
    myfile >> index;
    roads r[index];
    cout << endl << endl << endl << endl;//space between the two output sections
    cout << "    Name    " << "    Length " << " OneWay " << " Speed Limit" << endl;
    for (int i = 0; i < index; i++)
    {
        myfile >> r[i].name >> r[i].roadLength >> r[i].oneWay >> r[i].speedLimit;
        cout << r[i].name << "  " << r[i].roadLength << "  " << r[i].oneWay << "      " << r[i].speedLimit << endl;
    }
    //output repeats for each read file variable
}
