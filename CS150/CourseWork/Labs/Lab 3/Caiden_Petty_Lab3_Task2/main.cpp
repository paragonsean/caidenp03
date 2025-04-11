#include <iostream>
#include <fstream>
using namespace std;

const double INCREASE = 0.076;
int main()
{
    double oldSalary, salary, monthlySalary, retroactive;

    ofstream outData;
    outData.open("Output.txt");

    cout << "Enter current annual salary. " << endl
         << "I'll return a new annual, monthly," << endl
         << "and retroactive pay. " << endl;

    cin >> oldSalary;

    salary = oldSalary * (1 + INCREASE);
    monthlySalary = salary/12;
    retroactive = (salary - oldSalary)/2;

    cout << "New annual salary: " << salary << endl;
    cout << "New monthly salary: " << monthlySalary << endl;
    cout << "Retroactive salary due: " << retroactive << endl;

    outData << "New annual salary: " << salary << endl;
    outData << "New monthly salary: " << monthlySalary << endl;
    outData << "Retroactive salary due: " << retroactive << endl;

    outData.close();
    cout << endl << endl << endl;

    return 0;
}
