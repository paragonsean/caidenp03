#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//header libraries

using namespace std;

/*void openroad();
void openintersection();
*/

class roads
{
public:
    void readR();
    void setName(string);
    void setroadLength(double);
    void setoneWay(bool);
    void setspeedLimit(int);
    std::string getName();
    double getroadLength();
    bool getoneWay();
    int getspeedLimit();
private:
    std::string name;
    double roadLength;
    bool oneWay;
    int speedLimit;
};
//class to create all the variables and make them private


/*void openroad()
{
    ifstream myfile;
    myfile.open("roads.txt");
    if(myfile.fail())
    {
        cout << "file fail." << endl;
        exit(1);
    }
}

void openintersection()
{
    ifstream my2file;
    my2file.open("intersections.txt");
    if(my2file.fail())
    {
        cout << "file2 fail." << endl;
        exit(1);
    }
}
*/

#endif // INFO_H_INCLUDED
