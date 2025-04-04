#include <iostream>
#include <fstream>/// for the file output

using namespace std;

int main()

    {
    int cars[10];
    int sum = 0;
    int max = 0;///initialize max to 0
    int salesPerson;


    ifstream inFile;///get the infile
    inFile.open("cars.txt");

    for (int j = 0; j < 10; j++)
    {
        inFile >> cars[j];
         sum += cars[j];
    }



    cout << "The total number of cars sold = " << sum << endl;
    max = cars[0];

    salesPerson = 1;

    for (int j = 0; j < 10; j++)
    if (cars[j] > max)///switch the less than sign
    {
        max = cars[j];
        salesPerson = j+1;/// add one because the array starts at 0
    }
    cout << "The salesperson selling the maximum number of cars is salesperson "
    << salesPerson << endl;
    cout << "Salesperson " << salesPerson << " sold "
    << max << " cars last month." << endl;
    cout << endl;

    inFile.close();

return 0;
}
