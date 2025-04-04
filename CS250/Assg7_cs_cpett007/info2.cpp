#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "info.h"
#include "info2.h"
//header libraries
using namespace std;
//setter and getter functions to assign values to all the functions
void intersections::seteStreet(string E_street)
{
    eStreet = E_street;
}

void intersections::setnStreet(string N_street)
{
    nStreet = N_street;
}

void intersections::setwStreet(string W_street)
{
    wStreet = W_street;
}

void intersections::setStop(int stop_lights)
{
    numOfStopLights = stop_lights;
}

void intersections::setTraffic(int traffic_lights)
{
    numOfTrafficLights = traffic_lights;
}

string intersections::geteStreet()
{
    return eStreet;
}

string intersections::getnStreet()
{
    return nStreet;
}

string intersections::getwStreet()
{
    return wStreet;
}

string intersections::getsStreet()
{
    return sStreet;
}

int intersections::getstop()
{
    return numOfStopLights;
}

int intersections::gettraffic()
{
    return numOfTrafficLights;
}
//a multipurpose read function to assign and output the values from the getter and setter functions

void intersections::readI()
{
    int length;
    ifstream my2file;
    my2file.open("intersections.txt");
    if(my2file.fail())
    {
        cout << "file2 fail." << endl;
        exit(1);
    }
    my2file >> length;
    intersections i[length];

    cout << "   North      " << "   South   " << "        East    " << "    West    " << "        #Stops " << "#Lights    " << endl;
    for (int j = 0; j < length; j++)
    {
        my2file >> i[j].nStreet >> i[j].sStreet >> i[j].eStreet >> i[j].wStreet >> i[j].numOfStopLights >> i[j].numOfTrafficLights;
        cout << i[j].nStreet << "  " << i[j].sStreet << "  " << i[j].eStreet << "  " << i[j].wStreet << "  " << i[j].numOfStopLights << "    " << i[j].numOfTrafficLights << endl;
    }
}
