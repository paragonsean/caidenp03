#ifndef INFO2_H_INCLUDED
#define INFO2_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//header libraries

using namespace std;


class intersections
{
public:
    void readI();
    void setnStreet(string);
    void setwStreet(string);
    void setsStreet(string);
    void seteStreet(string);
    void setStop(int);
    void setTraffic(int);
    std::string getnStreet();
    std::string getwStreet();
    std::string geteStreet();
    std::string getsStreet();
    int getstop();
    int gettraffic();
private:
    std::string nStreet;
    std::string sStreet;
    std::string wStreet;
    std::string eStreet;
    int numOfStopLights;
    int numOfTrafficLights;
};
//class to create all the variables and make them private
#endif // INFO2_H_INCLUDED
