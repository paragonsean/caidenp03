#include "include/Population.h"
#include "include/Demands.h"
#include "include/RandD.h"
#include "include/FactoryMan.h"
#include "include/Design.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <random>


using namespace std;

int main()
{
    /*
    Pop -> Demands, ppoint.
    R&D -> Designs
    */
    int iterations;
    cout << "Welcome to the model factory!\nHow many iterations would you like to compute?\n" << endl;
    cin >> iterations;
    for(int i = 0; i < iterations; i++)
    {
        cout << "Working!" << endl;
    }

    return 0;
}
