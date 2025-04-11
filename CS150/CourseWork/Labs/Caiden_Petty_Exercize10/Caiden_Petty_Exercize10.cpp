#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    int *cars;///initialize the pointer variable
    cars = new int[10];///make a dynamic array
    int sum = 0;
    int max;
    int salesPerson;

    ifstream inFile;

    inFile.open("cars.txt");

    for (int j = 0; j < 10; j++)
    {
        inFile >> cars[j];
        sum = sum + cars[j];
    }

    cout << "The total number of cars sold = " << sum << endl;

    max = cars[0];
    salesPerson = 1;

    for (int j = 1; j < 10; j++)
        if (max < cars[j])
        {
           max = cars[j];
           salesPerson = j+1;
        }


    cout << "The salesperson selling the maximum number of cars is salesperson "
         << salesPerson << endl;

    cout << "Salesperson " << salesPerson << " sold "
         << max << " cars last month." << endl;


    cout << endl;


    inFile.close();
    return 0;
}

