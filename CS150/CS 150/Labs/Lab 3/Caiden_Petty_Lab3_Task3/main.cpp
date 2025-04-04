#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;

    string firstName, lastName, department;
    double grossSalary, bonus, taxRate;
    double distanceTraveled, travelTime;
    int numOfCoffeeCupsSold;
    double coffeeCupCost;
    double payCheck, averageSpeed, salesAmount;

    inFile.open("inData.txt");
    outFile.open("outData.txt");

    outFile << fixed << showpoint << setprecision(2);

    inFile >> firstName >> lastName >> department;
    inFile >> grossSalary >> bonus >> taxRate;
    inFile >> distanceTraveled >> travelTime;
    inFile >> numOfCoffeeCupsSold >> coffeeCupCost;

    outFile << "Monthly gross salary: $" << grossSalary
            << ", Monthly Bonus: " << bonus << "%, Taxes: "
            << taxRate << "%" << endl
            << "Paycheck: $";

    payCheck = grossSalary * (1 + bonus/100) * (1 - taxRate/100);
    outFile << payCheck
            << endl << endl;

    outFile << "Distance traveled: " << distanceTraveled
            << "Miles per hour " << endl << endl;

        outFile << "Average speed: " << averageSpeed
                << " miles per hour " << endl << endl;

        averageSpeed = distanceTraveled / travelTime;

        outFile << "Average speed: " << averageSpeed
                << "miles per hour" << endl << endl;

        outFile << "Number of coffee cups sold: " << numOfCoffeeCupsSold
                << ", Cost: $" << coffeeCupCost << " per cup" << endl;

        salesAmount = numOfCoffeeCupsSold * coffeeCupCost;

        outFile << "Sales amount = $" << salesAmount;

        inFile.close();
        outFile.close();

    return 0;
}
