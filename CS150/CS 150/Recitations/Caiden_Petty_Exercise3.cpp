#include <iostream>
#include <fstream> // title header needed to be included
using namespace std;

int main()
{
    ofstream outfile;//change i to an o
    double length, width;
    double Area;

 outfile.open("Outdata.txt");//outfile needed to be opened

 cout << "Input the length, then the width: " << endl;
 cin >> length;
 cin >> width;//prompt the user to input the variables, and include them

Area = length * width;

 outfile << "Area = " << Area << endl;

 outfile.close();
return 0;
}


