#include <iostream>
#include <string>
#include <iomanip>
#include <string>

using namespace std;

///struct
struct computerType
{
    string manufactuerer;
    string modelType;
    string processorType;
    int ram;
    int hardDriveSize;
    int yearBuilt;
    double price;
};

int main()
{
    ///declare variable for computer type
    computerType computer;

    cout << fixed << showpoint << setprecision(2);

    ///prompt the user to input the data about their computer
    cout << "Enter the name of the manufacturer: ";
    getline(cin, computer.manufactuerer);
    cout << endl;

    cout << "Enter the model of the computer: ";
    getline(cin, computer.modelType);
    cout << endl;

    cout << "Enter the processor type: ";
    getline(cin, computer.processorType);
    cout << endl;

    cout << "Enter the size of the RAM (In GB): ";
    cin >> computer.ram;
    cout << endl;

    cout << "Enter the size of the hard drive (in GB): ";
    cin >> computer.hardDriveSize;
    cout << endl;

    cout << "Enter the year the computer was built: ";
    cin >> computer.yearBuilt;
    cout << endl;

    cout << "Enter the price: ";
    cin >> computer.price;
    cout << endl;

    ///output the computer's data

    cout <<  "Manufacturer: " << computer.manufactuerer << endl;
    cout << "Model: " << computer.modelType << endl;
    cout << "Processor: " << computer.processorType << endl;
    cout << "Ram: " << computer.ram << endl;
    cout << "Hard drive size: " << computer.hardDriveSize << endl;
    cout << "Year built: " << computer.yearBuilt << endl;
    cout << "Price: $" << computer.price << endl;

    return 0;
}
