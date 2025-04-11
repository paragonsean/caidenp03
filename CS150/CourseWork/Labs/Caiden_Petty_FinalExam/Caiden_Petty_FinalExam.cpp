///Caiden Petty Lab Final
/// UIN 01204093
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct picnic
{
    string name;
    int bottledWater;
    int Snack;
    int Food;
    int Fruit;
    int Cups;
    int Plates;
    int Forks;
    int Spoons;
};

void mostWater (picnic potluck[]);

int main()
{
    ifstream infile;
    infile.open ("info.txt");

    if (!infile)
    {
        cout << "no file detected, ending" << endl;
        return 1;}


    int totalCups;
    int totalWater;
    int fluidOunces = 16.9 * totalWater;

    cout << "***********************************"
         << "\n Friends Potluck Picnic Information"
         << "\n***********************************" << endl;
    cout << "Name      Bottled-Water  Snack     Food     Fruit     Cups     Plates    Forks    Spoons"
         << "\n ***************************************************************************************"
         << endl;
         picnic potluck[5];
    for (int j = 0; j<5; j++)
    {
        infile >> potluck[j].name;
        infile >> potluck[j].bottledWater;
        infile >> potluck[j].Snack;
        infile >> potluck[j].Food;
        infile >> potluck[j].Fruit;
        infile >> potluck[j].Cups;
        infile >> potluck[j].Plates;
        infile >> potluck[j].Forks;
        infile >> potluck[j].Spoons;


    }
    for(int j=0; j<5;j++)
    {
         cout << left << setw(10) << potluck[j].name << "  " << potluck[j].bottledWater << "            " << potluck[j].Snack
             << "        " << potluck[j].Food << "       " << potluck[j].Fruit << "         " << potluck[j].Cups << "           " << potluck[j].Plates
             << "         " << potluck[j].Forks <<"       " << potluck[j].Spoons << endl;

    }
    mostWater(potluck);
    totalCups = potluck[1].Cups + potluck[0].Cups + potluck[2].Cups + potluck[3].Cups + potluck[4].Cups;
    cout << "\nThe total number of cups brought was: " << totalCups << endl;

    totalWater = 22;
    cout << totalWater << " bottles weighs " << fluidOunces << " fluid ounce." << endl;
    infile.close();
    return 0;
}

void mostWater (picnic potluck[])
{
    int i;
    int bestWater=0;
    for(i=1; i<5; i++)
    {

        if (potluck[i].bottledWater > potluck[bestWater].bottledWater)
            bestWater = i;
    }
    cout << potluck[bestWater].name << " brought the most water: " << potluck[bestWater].bottledWater << " bottles." << endl;
}
