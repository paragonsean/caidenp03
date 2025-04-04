#include <iostream>
#include <fstream>/// for the file output

using namespace std;

int main()

    {
    int cars[10];
    int sum = 0;
    int max;
    int salesPerson;

    ifstream inFile;
    inFile.open("cars.txt");

    for (int j = 0; j < 10; j++)
    {
        inFile >> cars[j];
    }

    sum = sum + cars[10];

    cout << "The total number of cars sold = " << sum << endl;
    max = cars[0];
    salesPerson = 1;
    for (int j = 1; j < 10; j++)
    if (max > cars[j])
    {
        max = cars[j];
        salesPerson = j;
    }
    cout << "The salesperson selling the maximum number of cars is salesperson "
    << salesPerson << endl;
    cout << "Salesperson " << salesPerson << " sold "
    << max << " cars last month." << endl;
    cout << endl;

    inFile.close();

return 0;
}
